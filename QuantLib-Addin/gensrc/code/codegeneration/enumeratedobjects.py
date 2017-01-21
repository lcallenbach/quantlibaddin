"""
 Python source for QuantLib addin in LibreOffice/Calc.
 Copyright (C) 2016 Lars Callenbach

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""


from code.codegeneration.codegeneration import CodeGeneration
from code.logging.logger import Logger
import sys



class EnumeratedObjects(CodeGeneration):
    """Class to generate code for enumerated objects. 
    
    Provides the implementation of the two functins generate_cpp() and 
    generate_hpp() for enumerated objects. 

    Variables:
        enumerated_types: Map of enumerated types (ParseMetaData.enumerations).
        conversions: Map of conversions from ParseMetaData.conversions.
        prefix: Idl type name prefix.
    """    
        
    def __init__(self, enumerated_types, conversions, prefix):
        CodeGeneration.__init__(self)
        self.enumerated_types = enumerated_types
        self.conversions = conversions
        self.prefix = prefix
        
        self._check()
        
    
    def generate_cpp(self):
        """Function to generate cpp code with implementations.
        
        This function defines per enumeration an exception class (if a parameter
        can not converted). The conversion from user interface to the object 
        will be defined parsing the enumerations. If for the conversion conv 
        the flag conv.flag is set for this object type the conversion back from
        the object to the conv.cpp type will be implemented also.
        
        The following rules apply for the conversion back:
            EnumeratedTypes can use conv.flag=='<<' 
            EnumeratedClasses must define the class function to access the 
                 attribute (e.g. 'name()' for ACTACT.name())
        
        Return:
            List of text code.
        """
        processed = set()
        text = ''
        lines = []
        
        for enum_key1 in self.enumerated_types:
            actual_class = self.enumerated_types[enum_key1]
            if not (actual_class in processed):
                processed.add( actual_class )

                Logger().debug('Processing '+actual_class)

                conv = self.find_conversion(actual_class)
                
                line = (0, '// generating data for %s ' % actual_class)
                lines.append(line)
                lines.append((0, ''))
                
                # exception definition (thrown for wrong parameters)               
                addin_classname = self.get_addintype(actual_class)
                line = (0, 'class %sError: public std::exception {' % \
                        addin_classname)
                lines.append(line)
                line = (1, 'const char * what () const throw () { ')
                lines.append(line)
                line = (2, 'return "No conversion defined for %s";' % \
                        actual_class)
                lines.append(line)
                line = (1, '};')
                lines.append(line)
                line = (0, '};')
                lines.append(line)
                lines.append((0, ''))
                
                # conversion to object                 
                line = (0, self.generate_declaration(enum_key1, conv, \
                                                     True)+'{')
                lines.append(line)                

                class_name = enum_key1.cpp
                typ_cpp = self.find_conversion(class_name).cpp                                
                line = (1, typ_cpp + ' fromtyp_cpp;')
                lines.append(line)

                conversion_func = self.find_conversion(class_name).fromidl
                if conversion_func=='Default':
                    conversion_func = 'interfaceToIdentity'
                line = (1, 'scalarInterfaceToCpp(fromtyp, fromtyp_cpp, %s);' \
                         % conversion_func)
                lines.append(line)
                lines.append( (1, '') )
                
                for enum_key2 in self.enumerated_types:
                    if self.enumerated_types[enum_key2]==actual_class:
                        fill = ''
                        if enum_key2.cpp=='std::string':
                            fill = '"'
                        text = 'if(fromtyp_cpp==%s(%s%s%s)) { ' % \
                            (enum_key2.cpp, fill, enum_key2.arg, fill)
                        line = (1, text)
                        lines.append(line)
                        
                        line = (2, 'totyp = %s;' % enum_key2.value)
                        lines.append(line)
                        line = (2, 'return;')
                        lines.append(line)
                        line = (1, '};')
                        lines.append(line)
                line = (1, 'throw %sError();' % addin_classname)
                lines.append(line)
                line = (0, '};')
                lines.append(line)
                lines.append((0, ''))
                
                if conv.flag is None:
                    continue
                
                # conversion from object back                 
                line = (0, self.generate_declaration(enum_key1, conv, \
                                                     False)+' {')
                lines.append(line)                
                if conv.flag=='<<' and conv.cpp=='std::string' and \
                  enum_key1.typ=='EnumeratedType':
                    line = (1, 'std::stringstream s;')
                    lines.append(line)
                    line =(1, 's << fromtyp;' )
                    lines.append(line)
                    line =(1, 'totyp = s.str();' )
                    lines.append(line)
                if conv.flag!='<<' and enum_key1.typ=='EnumeratedClass':
                    line =(1, 'totyp = fromtyp.%s;' % conv.flag ) 
                    lines.append(line)
                line = (0, '};')
                lines.append(line)
                lines.append((0, ''))

        return lines
    
        
    def generate_hpp(self):
        """Function to generate code for header file declarations.
        
        Return:
            List of text code
        """
        processed = set()
        lines = []
        
        for enum_key in self.enumerated_types:
            class_name = self.enumerated_types[enum_key]
            if not (class_name in processed):
                processed.add( class_name )           
                conv = self.find_conversion(class_name)
                line = (0, self.generate_declaration(enum_key, conv, True)+';')
                lines.append(line)
                if conv.flag is None:
                    continue
                line = (0, self.generate_declaration(enum_key, conv, \
                                                     False)+';')
                lines.append(line)
        return lines
    
        
    def generate_declaration(self, enum_key, conv, normal):
        """Function for declaration text for enumeration.
        
        This function returns the declaration of the enumeration. If normal is 
        False the conversion from the QuantLib object back to the C++ (using
        conversion.cpp as type) is declared.
        
        Arguments:
            enum_key: Enumeration key of type parsemetatda.Enumeration
            conv: Conversion for enumeration of type parsemetadata.Conversion
            normal: Boolean flag 
                True: from idl to QuantLib object
                False: from QuantLib object ot conv.cpp
        
        Return:
            String of declaration code. 
        """
        class_name = self.enumerated_types[enum_key]
        addinclass_name = self.get_addintype( class_name )
        
        text = ''
        if normal:
            typ = self.prefix+conv.idl
            text = 'void %sEnum(%s fromtyp, %s &totyp)' % \
                    (addinclass_name, typ, class_name)
        else:
            from_typ = conv.typ
            to_typ = conv.cpp
            text = 'void %sBack(%s fromtyp, %s &totyp)' % \
                    (addinclass_name, from_typ, to_typ)
                    
        return text

        
    def _check(self):
        """Procedure to check for consistency of enumerated types.
        
        Analyses the return types of enumerations. Exactly one should be 
        defined.
        Exits on error.
        """
        processed = set()
        
        for enum_key1 in self.enumerated_types:
            class_name = self.enumerated_types[enum_key1]
            if class_name in processed:
                continue            
            processed.add( class_name )
        
            arg_types = set()
            for enum_key2 in self.enumerated_types:
                if self.enumerated_types[enum_key2]==class_name:
                    arg_types.add( enum_key2.cpp )
                    if len(arg_types)>1:
                        Logger().error(\
                            'too many argument typs for enumerated class '+ \
                            class_name)
                        sys.exit(5)
                        
            if len(arg_types)==0:
                Logger().debug(enum_key1)
                Logger().error('no definition found for enumerated class '+ \
                    class_name)
                sys.exit(5)               
        
        
    def find_conversion(self, class_name):
        """Find a conversion for type class_name.
    
        Find an entry for class_name in the conversions generated. 
        
        Args:
            class_name: Name of class to look for. 
            
        Returns:
            Named tuple Conversion (defined in parsemetadata.py).
        """
        if class_name in self.conversions.keys():
            return self.conversions[class_name]
        return None


        
        
if __name__ == "__main__":
    import sys, os
    sys.path.append(os.path.join(sys.path[0], '..', '..'))
    from code.configuration.parsemetadata import ParseMetaData
    
    pmd = ParseMetaData('/work/QuantLib-Addin/gensrc/metadata', 'Calc')
    print(pmd.all_types)
    print(pmd.all_conversions)
    
    enum = EnumeratedObjects(pmd.enumerations, pmd.conversions, 'IDL_')
    enum.print_lines(enum.generate_hpp())
    enum.print_lines(enum.generate_cpp())
    
    
