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

from code.configuration.readconfiguration import ReadConfiguration
from code.patterns.singleton import Singleton
from code.logging.logger import Logger



class GensrcConfiguration(ReadConfiguration, metaclass=Singleton):
    """Class to read gensrc configuration.
    """    
    
    def __init__(self, path):
        """Constructor.
        
        Defines required_variables and reads configuration data.
        """        
        self.required_variables = ['gensrcPath', 'metadataPath', 
                                   'stubPath',   'configPath']
        ReadConfiguration.__init__(self, path)
        
        if not self.check_complete():
            Logger.error('could not read gensr configuration!')
            sys.exit(5)

            

if __name__ == "__main__":
    rc = GensrcConfiguration(str('../../'))
    print(rc.gensrcPath)
    

   