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
import os

from code.configuration.readconfiguration import ReadConfiguration
from code.logging.logger import Logger
from code.configuration.gensrcconfiguration import GensrcConfiguration



class AddinConfiguration(ReadConfiguration):
    """Class read relevant information from data file.

    This class reads all relevant information for addin source code generation.
    Some data are stored in files (patterns for replacement using pythons 
    dictionary methods).
    """    
    
    def __init__(self, path, suffix):
        """Constuctor.
        
        Sets the buffers if required. 
        
        Variables:
            path: Path to configuration file.
            suffix: Suffix of the file (must be defined).
        """
        Logger().debug('start addin configuration %s ...' % suffix)
        
        if len(suffix)==0:
            Logger().error('no suffix given')
            sys.exit(5)
                
        self.required_variables = ['namespace', 'codePath' ]
        ReadConfiguration.__init__(self, path, suffix)

        if not self.check_complete():
            Logger.error('could not read addin configuration for %s!' % suffix)
            sys.exit(5)

        self.text_addin_cpp = 'addin.cpp'
        self.text_addin_hpp = 'addin.hpp'
        self.text_idl_func = 'idl.func'
        self.text_idl_header = 'idl.header'        
        self.suffix = suffix.lower()
        
        self.read_buffers()
        
        Logger().debug('end addin configuration %s ...' % suffix)
    
        
    def read_buffers(self):
        """Procedure to read buffers.
        """
        variables = ['text_idl_func', 'text_idl_header', 
                     'text_addin_cpp', 'text_addin_hpp']
                     
        for var in variables:
            if hasattr(self, var):
                Logger().debug('getting variable %s' % var)
                file_name = ''
                file_name = file_name+GensrcConfiguration().stubPath+os.path.sep 
                file_name = file_name+'stub.'+self.suffix+'.'+getattr(self, var)
                with open(file_name) as f:
                    text = f.read()
                    setattr(self, var, text)
                    Logger().debug('setting to  --- \n%s\n---' % text)
            else:
                Logger().error('could not read config file %s for %s' %(var, self.suffix_) )

                
        
        
if __name__ == "__main__":
    gensrc_configuration = GensrcConfiguration('../..')
    addin = AddinConfiguration('../../config', 'calc')
