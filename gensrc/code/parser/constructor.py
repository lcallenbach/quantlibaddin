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


import sys
from code.logging.logger import Logger
from code.parser.parameter import Parameter
from code.parser.parameterlist import ParameterList
from code.parser.parser import Parser
from pyparsing import Regex, Forward, ZeroOrMore, Optional, ParseException


    
class Constructor(ParameterList, Parser):
    """Class to parse constructor information.

    The parameter (return type, member function invocation, parameter list) 
    will be parsed by this class.
    
    Inherits from:
        ParameterList: Storage of parameter information in list.
        Parser: Provides procedure parse()
        
    Variables:
        constructor: Fully qualified constructor invocation name.
        class_name: Class name of constructor.
    """    
    
    def __init__(self, argument):
        """Constructor.
        
        Variables:
            argument: Data to be parsed.
        """
        ParameterList.__init__(self)
        
        self.constructor = None
        self.class_name = None
        self.template_args = None

        self.parse(argument)
        
        
    def parse(self, argument):
        """Procedure to parse constructor information.
        
        Variables:
            argument: Data to be parsed.
        """
        # pyparsing syntax parser definition
        template = ZeroOrMore(' ') +  Regex(r'<[a-zA-Z0-9\,\ ]+>') + \
                 ZeroOrMore(' ')
        classQualifier      = Forward()
        classQualifierRegex = Regex(r'[a-zA-Z_0-9]+::')
        classQualifier     << classQualifierRegex + ZeroOrMore(classQualifier)
        className = Regex(r'[a-zA-Z_0-9]+')
        classAll  = (ZeroOrMore(classQualifier) + className + Optional( \
                      Regex(r'<[a-zA-Z0-9\,\ :]+>'))).setResultsName('constructor') 

        anyString =  ( Regex(r'(.*)') ) .setResultsName('parameters_text')
        constructor = Optional(template).setResultsName('template') + \
                classAll +  anyString
        
        #parse argument 
        parse = None
        try:
            parse = constructor.parseString(argument, True )
        except ParseException as err:
            Logger().debug(err.line)
            Logger().debug(str(err))
            Logger().error('constructor parsing error "%s"' % argument)
            sys.exit(5)

        try:
            Logger().debug('entering conversion ...')
            
            #set constructor and class_name
            self.constructor = ''
            for item in parse['constructor']:
                self.constructor = self.constructor + item
                self.class_name = item

            Logger().debug('constructor %s' % self.constructor)
            
            #analyse parameter list 
            Logger().debug('constructor parameter_list:')
            parameters_text = parse['parameters_text'][1:-1]

            #analyse parameter list - first step: include object parameter
            first_parameter = 'std::string ObjectId '
            if parameters_text:
                parameters_text = first_parameter + ', ' + parameters_text
            else:
                parameters_text = first_parameter

            if parameters_text:                
                liste = parameters_text.split(',')
                Logger().debug(liste)
                pos = 0
                for item in liste:
                    Logger().debug('processing '+item)
                    text = item.strip()
                    if text:
                        parameter = Parameter(text)
                        self.parameter_list.append( parameter )
                    else:
                        Logger().error('constructor error parameter "%s" in \
                            "%s" at position %d.' % (item, liste, pos))
                        sys.exit(5)
                    pos += 1        
                    Logger().debug('OK')

            if 'template' in parse.keys() is not None:
                self.template_args = []
                args = parse['template'][0][1:-1].split(',')
                for arg in args:
                    self.template_args.append(arg.strip())
                Logger().debug('template args '+str(self.template_args))
                
            Logger().debug('leaving conversion ...')
        except:
            Logger().error('constuctor conversion error "%s" (%d)' % \
                   (argument, pos))
            sys.exit(5)
    
        
    def get_classname(self):
        """Function to return fully qualified class name .
        """
        return self.constructor
        
    def get_templateargs(self):
        """Function to return template arguments.
        """
        return self.template_args
        
#    
#        
#    def get_classname(self):
#        """Function to return class name.
#        """
#        return self.class_name

        
        
if __name__ == "__main__":
    source_code = '<TraitsID>QuantLib::Ql<Test>(std::vector< PP::QuantLib::Day> Day, Date dat, d d)'    
#    source_code = 'QuantLib::Ql<Test>(std::vector< PP::QuantLib::Day> Day, Date dat, d d)'    
    Logger().debug(Constructor(source_code).get_classname())
    Logger().debug(Constructor(source_code).get_templateargs())
#    source_code = 'QuantLib::Ql(std::vector< PP::QuantLib::Day> Day, Date dat, d d)'
#    Logger().debug(Constructor(source_code).get_classname())
#    Logger().debug(Constructor(source_code).get_templateargs())
