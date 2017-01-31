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
from pyparsing import Regex, Forward, ZeroOrMore, ParseException, Combine

 
   
class MemberFunction(ParameterList, Parser):
    """Class to parse member function information.

    The parameter (return type, member function invocation, parameter list) 
    will be parsed by this class.
    
    Inherits from:
        ParameterList: Storage of parameter information in list.
        Parser: Provides procedure parse()
        
    Variables:
        function_name: Name function invocation name.
        return_type: Return type of member function. 
    """    
    
    def __init__(self, argument):
        """Constructor.
        
        Variables:
            argument: Data to be parsed.
        """
        ParameterList.__init__(self)
        
        self.function_name = None
        self.return_type = None
        self.return_type_parameter = None
        
        self.parse(argument)
        
        
    def parse(self, argument):
        """Procedure to parse constructor information.
        
        Variables:
            argument: Data to be parsed.
        """
        # pyparsing syntax parser definition
        classQualifier      = Forward()
        classQualifierRegex = Regex(r'[a-zA-Z_0-9]+::')
        classQualifier << ZeroOrMore(' ') + classQualifierRegex + \
                            ZeroOrMore(classQualifier)
        className = Regex(r'[a-zA-Z_0-9]+')
        classAll  = (ZeroOrMore(classQualifier) + className)

        vectorWord = Forward()
        vectorWord << ((ZeroOrMore(' ') + 'std::vector<' + ZeroOrMore(' ') + \
                       vectorWord + ZeroOrMore(' ') + '>') |  classAll  )

        anyString =  ( Regex(r'(.*)') ) .\
                        setResultsName('parameters_text')

        function = vectorWord.setResultsName('return_type') + \
                        ZeroOrMore(' ') + Combine(('operator()' | classAll)).\
                        setResultsName('function_name') + anyString
        
        #parse argument 
        parse = None
        try:
            parse = function.parseString(argument, True)
        except ParseException as err:
            Logger().debug(err.line)
            Logger().debug(str(err))
            Logger().error('memberfunction parsing error "%s"' % argument)
            sys.exit(5)
        
        try:
            Logger().debug('entering conversion ...')
            print(parse)
            
            #set return_type and function_name            
            self.return_type = ''
            for item in parse:
                if item!=parse['function_name']:
                    self.return_type = self.return_type + item
                else:
                    break
            Logger().debug('memberfunction return_type %s' % self.return_type)
            
            text = self.return_type+' ReturnType'
            self.return_type_parameter = Parameter(text)
            
            self.function_name = parse['function_name']
            Logger().debug('memberfunction function_name %s' % 
                self.function_name)
            
            Logger().debug('memberfunction parameter_list:')
            parameters_text = parse['parameters_text'][1:-1]

            #analyse parameter list - first step: include object parameter
            first_parameter = 'std::string ObjectId '
            if parameters_text:
                parameters_text = first_parameter + ', ' + parameters_text
            else:
                parameters_text = first_parameter
                
            # parse argument list 
            if parameters_text:                
                liste = parameters_text.split(',')
                Logger().debug(liste)
                pos = 0
                while pos<len(liste):
                    text = liste[pos].strip()
                    count = self.get_brackets(text)
                    while count!=0 and pos<len(liste):
                        pos += 1
                        if pos<len(liste):
                            text = text+','+liste[pos]
                            count = self.get_brackets(text)
                    Logger().debug('processing '+text+' '+str(count))
                    if text and count==0:
                        parameter = Parameter(text)
                        self.parameter_list.append( parameter )
                    else:
                        Logger().error('memberfunction error parameter "%s" in \
                            "%s" at position %d.' % (text, liste, pos))
                        sys.exit(5)
                    pos += 1      
                
            Logger().debug('leaving conversion ...')
        except:
            Logger().error('memberfunction conversion error "%s"' % argument)
            sys.exit(5)
        
        
    def get_returntype(self):
        """Function to provide return type of function call.
        """
        return self.return_type
        
        
    def get_returntype_parameter(self):
        """Function to provide return type of function call.
        """
        return self.return_type_parameter
        
        
    def get_functionname(self):
        """Function to return function name of function call.
        """
        return self.function_name
       
        
            
if __name__ == "__main__":
#    source_code = 'std::vector<QuantLib::Ql> func(std::vector< PP::QuantLib::Day> Day, Date dat, d d)'
    source_code = 'std::vector<QuantLib::Ql> operator()(std::vector< PP::QuantLib::Day> Day, Date dat, d d)'
    source_code = 'void Addin::AddinSettings::setEvaluationDate(QuantLib::Date Date)'
    
    print(MemberFunction(source_code).get_functionname())
