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
import re

from code.logging.logger import Logger



class ReadConfiguration:
    """Class to read configuration data.

    The file will be read and all first parameters of a line will be set as 
    attributes with values (determined by second parameter).
        
    Variables:
        required_variables: Names of variables that must be set in file. 
    """    
    
    def __init__(self, path, suffix=''):
        """Constructor parses the file 'configuration'+suffix+'.txt' under path.
        """        
        self.required_variables = []
        
        separator = os.path.sep        
        found_variables = set()
        file_name = path+separator+str('configuration')+suffix+str('.txt')

        if os.path.isfile(file_name):
            file = open(file_name, str('r'))
            for line in file.readlines():
                line = re.sub(r"\s+", ' ', line)
                content = line.strip(str('\n')).split(str(' '))
                variable = content[0]
                if variable in found_variables:
                    print(str('duplicated variable %s in file %s') % 
                            (variable, file_name))
                else:
                    setattr(self, variable, content[1])
            file.close()
            Logger().info(str('configuration file %s read' % (file_name)) ) 
        else:
            Logger().error(str('file %s does not exist' % (file_name)) )
            
            
    def check_complete(self):
        """Function to check for completeness.
        """
        for name in self.required_variables:
            if hasattr(self, name)==False:
                Logger().debug('variables not complete')
                return False
        Logger().debug('variables complete')
        return True

        

if __name__ == "__main__":
    rc = ReadConfiguration(str('../../'), str(''))
    print(rc.gensrcPath)
