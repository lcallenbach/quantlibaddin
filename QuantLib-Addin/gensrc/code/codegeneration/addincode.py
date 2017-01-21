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
from code.codegeneration.addinclasses import AddinClasses
from code.codegeneration.enumeratedobjects import EnumeratedObjects



class AddinCode(CodeGeneration):
    """Class to generate gather code and store it in files. 
    
    Provides the implementation of the two functins generate_cpp() and 
    generate_hpp() for objects with constructors or member functions. 
    
    This class invokes code generation from addinclasses.py and 
    enumeratedobjects.py and combines both parts. 

    Variables:
        conversions: Conversions (from parsemetadata.py)
        constructors: Constructors (from parsemetadata.py)
        enumerations: Enumerations (from parsemetadata.py)
        memberfunctions: MemberFunctions (from parsemetadata.py)
        template_arguments: Template arguments (from parsemetadata.py)
        idl_object_type: Class of object in IDL code
        idl_to_cpp: Prefix for variables (e.g. 'IDL_')
        addin_name: Addin name. 
        idl_suffix: Suffix for idl variables (e.g. '_any' for Calc)
    """    
    
    def __init__(self, conversions, constructors, enumerations, \
                 memberfunctions, template_arguments, functions, \
                 idl_object_type, idl_to_cpp, addin_name, idl_suffix):        
        CodeGeneration.__init__(self)
        self.constructors = constructors
        self.memberfunctions = memberfunctions
        self.template_arguments = template_arguments
        self.functions = functions
        self.enumerations = enumerations
        self.conversions = conversions
        self.addin_name = addin_name
        self.idl_suffix = idl_suffix
        
        self.enumerations_code = EnumeratedObjects(enumerations, \
                    self.conversions, idl_to_cpp)
        self.addin_classes_code = AddinClasses(constructors, self.conversions, \
                    memberfunctions, idl_object_type, idl_to_cpp, \
                    self.enumerations, self.template_arguments, self.functions, \
                    self.idl_suffix)
        
        
    def generate_cpp(self):        
        """Implementation of the abstract class for cpp code generation.
        
        This function generates the C++-cpp code for the addin code (not the
        interface code to LibreOffice/Calc).
        
        Return:
            List of code lines of type Tuple(idention, code text).
        """
        lines = []
        line = '#include <addin.hpp>'        
        lines.append((0, line))
        
        line = 'namespace Addin {'
        lines.append((0, line))
        code = self.addin_classes_code.generate_cpp()
        lines += self.shift_text(1, code)
        code = self.enumerations_code.generate_cpp()
        lines += self.shift_text(1, code)
        lines.append((0,'};'))
        
        return lines
        
        
    def generate_hpp(self):
        """Implementation of the abstract class for hpp code generation.
        
        This function generates the C++-hpp code for the addin code (not the
        interface code to LibreOffice/Calc).
        
        Return:
            List of code lines of type Tuple(idention, code text).
        """
        lines = []
        line = '#ifndef __addin_hpp__'
        lines.append((0, line))
        line = '#define __addin_hpp__'
        lines.append((0, line))
        line = '#include <oh/object.hpp>'      
        lines.append((0, line))
        line = '#include <oh/repository.hpp>'        
        lines.append((0, line))
        line = '#include <qlo/all.hpp>'        
        lines.append((0, line))
        line = '#include <idltypes.hpp>'
        lines.append((0, line))
        line = '#include <idlconversions.hpp>'
        lines.append((0, line))
        line = '#include <iostream>'
        lines.append((0, line))

        processed_includefiles = set()
        for maps in [self.constructors, self.enumerations, \
          self.memberfunctions]:            
            for key in maps.keys():
                file_name = key[1]
                if not (file_name in processed_includefiles):
                    processed_includefiles.add( file_name )
                    line = '#include <%s>' % file_name 
                    lines.append((0, line))

        line = 'namespace Addin {'
        lines.append((0, line))
        code = self.addin_classes_code.generate_hpp()
        lines += self.shift_text(1, code)
        code = self.enumerations_code.generate_hpp()
        lines += self.shift_text(1, code)
        line = '};'
        lines.append((0, line))
        line = '#endif'
        lines.append((0, line))
        
        return lines