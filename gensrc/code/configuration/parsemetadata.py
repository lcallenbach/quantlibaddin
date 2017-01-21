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


import os
import imp
import sys

from collections import namedtuple
from code.logging.logger import Logger
from code.parser.constructor import Constructor
from code.parser.memberfunction import MemberFunction
from code.parser.parameter import Parameter



Conversion = namedtuple('Converison', 'typ cpp idl fromidl toidl flag')
def make_conversion(typ='', cpp='', idl='', toidl='', fromidl='', flag=None):
    return Conversion(typ, cpp, idl, toidl, fromidl, flag)
    
Type = namedtuple('Type','typ incfile class_name memfunc addin_name')
def make_type(typ='', incfile='', class_name='', memfunc='', addin_name=''):
    return Type(typ, incfile, class_name, memfunc, addin_name)

Enumeration = namedtuple('Enum', 'typ incfile class_name cpp arg value')
def make_enumeration(typ='', incfile='', class_name='', cpp='', arg='', value=''):
    return Enumeration(typ, incfile, class_name, cpp, arg, value)

TemplateArgument = namedtuple('TemplArg', 'typ incfile name cpp arg value addin_name')
def make_templateargument(typ='', incfile='', name='', cpp='', arg='', value='', \
                          addin_name=''):
    return TemplateArgument(typ, incfile, name, cpp, arg, value, addin_name)


    
class ParseMetaData(object):
    """Class to store meta data.
    
    This class parses all information under metdata. It looks for conversions
    under the variable ImplicitConversiosXXX (e.g. ImplicitConversionsCalc) 
    and QuantLibTypes. Both variables should be lists of well defined types. 
    

    Variables:
        all_conversions: List of all conversions stored under path.
        all_types: List of all types under path.
    """    
    
    def __init__(self, path, addin_name):       
        """Constructor that initiates parsing the files.
    
        Initializes data and calls process_files(). The data are stored in 
        the local variables self.all_conversions and self.all_types. The names 
        of the variables to look at are defined in self.conversions and 
        self.types.
    
        Args:
            path: Path to look at python files (string).
            addin_name: Name of the addin (e.g. 'Calc') 
        """
        self.conversions = str('ImplicitConversions')+addin_name
        self.types = str('QuantLibTypes')
        
        self.all_conversions = []
        self.all_types = []        

        self.count = [0, 0]
        
        Logger().info('variable name for conversions: %s' % self.conversions)
        Logger().info('variable name for types:       %s' % self.types)
        
        byte_code_config = sys.dont_write_bytecode
        sys.dont_write_bytecode = True
        try:
            self.process_files(path)
        except:
            Logger().error('ParseMetaDate: error parsing files')
            sys.exit(5)
            
        sys.dont_write_bytecode = byte_code_config
        
        Logger().info('counter for types:       %4d' % (self.count[0]))
        Logger().info('counter for conversions: %4d' % (self.count[1]))

        Logger().info('starting parsing information...')
        
        self.memberfunctions = None
        self.constructors = None
        self.enumerations = None
        self.conversions = None
        self.template_arguments = None
        self.functions = None
        
        self.parse_conversions()

        self.parse_enumerations()
        self.parse_templatearguments()

        self.parse_constructors()
        self.parse_memberfunctions()
        
        self.parse_functions()
        
        Logger().info('end parsing information...')
            
            
    def process_files(self, path):
        """Parse all files under path for relevant addin information.
    
        Looks under path for *.py files an parses them following for the chosen
        addin. Uses the loading of modules and inspection of attributes in the 
        loaded module. If the variable name exists in the loaded module it the
        content of the list will be added to the varaibale allConversions or 
        allTypes.
    
        Args:
            path: Path to look at python files (string).
        """
        for folder, subs, files in os.walk(path):
            for file in files:
                file_name = os.path.join(folder, file)
                if file_name[-2:]=='py':
                    Logger().info('processing '+file_name)
                    module = imp.load_source('', file_name)
                    if hasattr(module, self.types):
                        data = getattr(module, self.types)
                        if data:
                            self.all_types.extend(data)
                            self.count[0] += 1
                        setattr(module, self.types, [])
                    if hasattr(module, self.conversions):
                        data = getattr(module, self.conversions)
                        if data:
                            self.all_conversions.extend(data)
                            self.count[1] += 1
                        setattr(module, self.conversions, [])
                

    def parse_types(self, text, parse_all=False, match_first=False):
        """Generate Constructor, MemberFunction objects from types.
    
        Iterate over all entries of self.all_types and analyses the definitions
        to generate Constructor und MemberFunction objects. Returns an
        dictionary with the entry from self.all_types as key. Uses string
        comparison to look for text in the first type entry (matchFirst for 
        matching the first characteres of length text).
    
        Args:
            text: Text string to look for (e.g. 'Constructor').
            parse_all: Boolean value to parse constructor and member function 
                if true.
            match_first: Boolean variabel indication matching the first string 
                of the analyzed string.
        
        Returns:
            Dictionary with key = type (list of values) and objects 
                (constructors and/or member functions).
        """
        results = {}

        for item in self.all_types:
            if len(item)!=5:
                continue
            
            addin_typ = make_type(*item)
            typ = addin_typ.typ
            if (typ[:len(text)]==text and match_first) or typ==text:
                objects = []
                if len(addin_typ.class_name)>0:
                    objects.append( Constructor(addin_typ.class_name) )
                else:
                    objects.append( None )
                
                if parse_all:
                    objects.append( MemberFunction(addin_typ.memfunc) )
                else:
                    objects.append( None )
                results[addin_typ] = objects

        return results
        
        
    def parse_constructors(self):
        """Wrapper to find constructors.
    
        Iterate over all entries of self.all_types and look for the text 
        'Constructor' at the beginning. Do not parse member function 
        information. Modify parameter list of constructors if template 
        arguments are provided.
        """
        self.constructors = self.parse_types('Constructor', False)
        
        for addin_typ in self.constructors:
            constr = self.constructors[addin_typ][0]
            addin_name = addin_typ.addin_name
            template_args = constr.get_templateargs()
            if template_args is not None:
                templ_para_list = []
                for arg_name in template_args:
                    names = set()
                    for templ_arg in self.template_arguments:
                        if templ_arg.name in names:
                            continue
                        if templ_arg.name==arg_name and (templ_arg.addin_name \
                          ==addin_name or templ_arg.addin_name==''):
                            names.add(templ_arg.name)
                            typ_cpp = templ_arg.cpp
                            text = typ_cpp + ' ' + arg_name
                            templ_para_list.append( Parameter(text) )
                    Logger().debug(arg_name)
                    Logger().debug(addin_name)
                    if len(names)<1:
                        sys.exit(5)
                para_list = constr.get_parameters()
                new_list = []
                new_list.append(para_list[0])
                for para in templ_para_list:
                    new_list.append(para)
                for para in para_list[1:]:
                    new_list.append(para)
                constr.parameter_list = new_list
                self.constructors[addin_typ][0] = constr

                    
    def parse_memberfunctions(self):
        """Wrapper to find member functions.
    
        Iterate over all entries of self.all_types and look for the text 
        'MemberFunction' at the beginning. Constructor information is 
        required to attach the member function to the right addin class 
        (defined by the constructor). 
        """
        self.memberfunctions =  self.parse_types('MemberFunction', True)
        
                
    def parse_functions(self):
        """Wrapper to find functions.
    
        Iterate over all entries of self.all_types and look for the text 
        'Function' at the beginning. 
        """
        self.functions =  self.parse_types('Function', True)

        
    def parse_enumerations(self):
        """Generate enumeration information from types.
    
        Iterate over all entries of self.all_types and analyses the definitions
        to look for enumeraton definitions. Looks for matching strings 
        'EnumeratedClass' and 'EnumeratedType'.
        """
        results = {}

        for item in self.all_types:
            if len(item)!=6:
                continue
            
            data = make_enumeration(*item)
            if data.typ=='EnumeratedClass':
                class_name_constructor = Constructor(data.class_name) 
                results[data] = class_name_constructor.get_classname()
            if data.typ=='EnumeratedType':
                results[data] = data.class_name

        self.enumerations = results


    def parse_conversions(self):
        """Generate conversion definitions per type.
    
        Iterate over all entries of self.all_conversions and analyses the 
        definition. 
            
        Returns:
            Dictionary with key = class used in conversion.
        """
        results = {}

        for item in self.all_conversions:
            data = make_conversion(*item)
            typ = data.typ
            if typ is None:
                Logger().error('could not convert data set ' + str(item))
                continue

            if typ in results.keys():
                Logger().error('duplicated data for conversion of type ' + typ)
                sys.exit(5)
            else:
                results[typ] = data

        self.conversions = results
        
        
    def parse_templatearguments(self):
        """Generate template arguments.
    
        Iterate over all entries of self.all_types and analyses the template
        definition. 
            
        Returns:
            Dictionary of type TemplateArgument with key = (name, addin_name).
        """        
        results = []

        for item in self.all_types:
            if item is None or len(item)!=7 or item[0]!='TemplateArgument':
                continue
            
            data = make_templateargument(*item)
            typ = data.typ
            if typ is None:
                Logger().error('could not convert data set ' + str(item))
                continue

            if data in results:
                Logger().error('duplicated data for template argument ' + \
                        str(data))
                sys.exit(5)
            else:
                results.append(data)

        self.template_arguments = results      

    
    def find_conversion(self, default_class, class_name):
        """Find a conversion for type class_name using a default class.
    
        Find an entry for class_name in the conversions generated. The 
        position parameter determines which conversion information should 
        be returned.
            
        Returns:
            Named tuple Conversion (defined in parsemetadata.py).
        """
        if self.conversions is None:
            Logger().error('could not find conversion in empty dictionary')
            return None
        
        typ = default_class
        if typ in self.conversions.keys():
            typ = self.conversions[typ]
        if class_name in self.conversions.keys():
            typ = self.conversions[class_name]

        return typ


        
    def find_idltype(self, default_class, class_name):
        """Wrapper to find conversion type for class_name.
            
        Returns:
            String with idl conversion type.
        """
        return self.find_conversion(default_class, class_name).idl
        


        
if __name__ == "__main__":
    pmd = ParseMetaData('/work/QuantLib-Addin/gensrc/metadata', 'Calc')
    print(pmd.all_types)
    print(pmd.all_conversions)
    

            
            
            
        
            
            