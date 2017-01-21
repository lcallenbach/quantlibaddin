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


import logging
import inspect

from code.patterns.singleton import Singleton


LOGGING_FILENAME = str("gensr.log")



class Logger(metaclass=Singleton):
    
    def __init__(self):
        # set up logging to file 
        logging.basicConfig(level = logging.INFO,
                        format   = '%(name)s: %(levelname)-8s %(message)s',
                        filemode = 'w')
        
        self.logger_ = logging.getLogger('gensrc')
        self.logger_.setLevel( logging.DEBUG )
        
        fileLogger = logging.FileHandler(LOGGING_FILENAME, 'w')
        fileLogger.setLevel(logging.INFO)
        formatter = logging.Formatter('%(name)s: %(levelname)-8s %(message)s')
        # tell the handler to use this format
        fileLogger.setFormatter(formatter)
        self.logger_.addHandler(fileLogger)

    def info(self, msg):
        frame = inspect.currentframe()
        text = '%60s %4d %s' % (inspect.getouterframes(frame)[1].filename, 
                    inspect.getouterframes(frame)[1].lineno, msg)
        self.logger_.debug(text)
        
    def warn(self, msg):
        frame = inspect.currentframe()
        text = '%60s %4d %s' % (inspect.getouterframes(frame)[1].filename, 
                    inspect.getouterframes(frame)[1].lineno, msg)
        self.logger_.debug(text)

    def error(self, msg):
        frame = inspect.currentframe()
        text = '%60s %4d %s' % (inspect.getouterframes(frame)[1].filename, 
                    inspect.getouterframes(frame)[1].lineno, msg)
        self.logger_.debug(text)
        
    def debug(self, msg):
        frame = inspect.currentframe()
        text = '%60s %4d %s' % (inspect.getouterframes(frame)[1].filename, 
                    inspect.getouterframes(frame)[1].lineno, msg)
        self.logger_.debug(text)
