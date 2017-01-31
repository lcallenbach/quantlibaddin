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
from code.parser.parser import Parser
from pyparsing import Regex, Forward, ZeroOrMore, Optional, ParseException, \
    Keyword



class Parameter(Parser):
    """Class to parse parameter information.

    The parameter will be parsed by this class. Parameters are of the type 
    Type and Name. This function determines the dimension of the variable and
    analyses whether it is a handle of a boost::shared_ptr.
    
    Inherits from:
        Parser: Provides procedure parse()
        
    Variables:
        class_name: Fully qualified class name of the variable.
        variable_name: Name of the variable.
        default_value: C++ default value.
        dimension: dimension of variable.
        is_handle: Bool if variable is a Handle.
        is_shared_ptr: Bool if variable is a boos::shared_ptr.
    """    
    
    def __init__(self, argument):
        """Constructor.
        
        Variables:
            argument: Data to be parsed.
        """
        self.class_name = None
        self.variable_name = None
        self.default_value = None
        self.dimension = 0
        self.is_handle = False
        self.is_sharedptr = False
        
        self.parse(argument)
        
        
    def parse(self, argument):
        """Constructor.
        
        Variables:
            argument: Data to be parsed.
        """
        # pyparsing syntax parser definition
        classQualifier      = Forward()
        classQualifierRegex = Regex(r'[a-zA-Z_0-9]+::') 
        classQualifier     << classQualifierRegex + ZeroOrMore(classQualifier)
        className  = Optional(classQualifier) + \
                        ~(Keyword('Handle') | Keyword('shared_ptr') | \
                          Keyword('vector')) + \
                        Regex(r'[a-zA-Z_0-9_]+') 
        
        templClass = Forward()
        templClass << (className + Optional( '<' + \
                                  templClass + ZeroOrMore(',' + \
                                  templClass) + '>'))\
                             .setResultsName('class_name')
    
        handle    = classQualifier + 'Handle<' + templClass + '>'
        sharedPtr = 'boost::shared_ptr<' + templClass + '>'
        
        allTypes  =  templClass | handle | sharedPtr
    
        vectorWord = Forward()
        vectorWord << ('std::vector<' + vectorWord  + '>' | allTypes)
        
        variableWord = Regex(r'[a-zA-Z_]+[a-zA-Z0-9]*').\
                        setResultsName('variable_name')
        
        defaultValue = ZeroOrMore(' ') + '=' + ZeroOrMore(' ') + \
                        Regex(r'.+').setResultsName('default_value')
#                        Regex(r'[()a-zA-Z0-9<>:\., ]+').\
#                              setResultsName('default_value')
        parameter = ZeroOrMore(' ') + vectorWord + variableWord + \
                        Optional( ZeroOrMore(' ') + defaultValue )
        
        #parse argument 
        parse = None
        try:
            parse = parameter.parseString(argument, True )
        except ParseException as err:
            Logger().debug(err.line)
            Logger().debug(str(err))
            Logger().error('parameter parsing error "%s"' % argument)
            sys.exit(5)

        try:            
            Logger().debug('entering conversion ...')
            
            #set class_name and variable_name
            self.class_name = ''
            for item in parse['class_name']:
                self.class_name = self.class_name + item.strip()
            self.variable_name = parse['variable_name'].strip()
            
            # analyse for handle and shared_ptr
            self.is_handle = False
            if parse.asList().count('Handle<')>=1 or \
              parse.asList().count('Handle')>=1:
                self.is_handle = True
            
            self.is_sharedptr = False
            if parse.asList().count('boost::shared_ptr<')>=1 or \
              parse.asList().count('boost::shared_ptr')>=1:
                self.is_sharedptr = True
            
            #sets default value 
            if 'default_value' in parse.keys():
                self.default_value = parse['default_value']
            
            #determine dimension
            self.dimension = parse.asList().count('std::vector<')

            Logger().debug('Class      '+self.class_name)
            Logger().debug('Variable   '+self.variable_name)
            Logger().debug('Handle     '+str(self.is_handle))
            Logger().debug('SharedPtr  '+str(self.is_sharedptr))
            Logger().debug('Dimension  '+str(self.dimension))
            Logger().debug('Default    '+str(self.default_value))

            Logger().debug('leaving conversion ...')
        except:
            Logger().error('parameter conversion error "%s"' % argument)
            sys.exit(5)
    
            
    def get_classname(self):
        """Function to return class name.
        """
        return self.class_name
        
        
    def get_dimension(self):
        """Function to return dimension.
        """
        return self.dimension
        
        
    def get_variablename(self):
        """Function to return variable name.
        """        
        return self.variable_name
        
        
    def get_defaultvalue(self):
        """Function to return default value.
        """        
        return self.default_value
            
        

if __name__ == "__main__":
#    source_code = 'std::vector< QuantLib::Handle< QuantLib::Day>> Day'
#    source_code = 'std::vector< PP::QuantLib::Day> Day'
#    source_code = 'std::vector<boost::shared_ptr< ql::Day<Y> > > Day=1'
#    source_code = 'std::vector< boost::shared_ptr< BootstrapHelper<YieldTermStructure> > > BootstrapInstruments'
#    source_code = 'std::vector< boost::shared_ptr< B<Y> > > BootstrapInstruments'
#    source_code = 'B<Y> BootstrapInstruments=1'
    source_code = 'boost::shared_ptr<QuantLib::Quote < Yellow > > Spread = QuantLib::Quote()'
    Parameter(source_code)
