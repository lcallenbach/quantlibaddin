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


from code.addin.addinlist import AddinList
from code.logging.logger import Logger
from code.configuration.gensrcconfiguration import GensrcConfiguration
import getopt
import sys


LOGGING_FILENAME = 'gensrc.log'

LICENSE = """
 Python source for QuantLib addin in LibreOffice/Calc.
 Copyright (C) 2016 Lars Callenbach
 This program comes with ABSOLUTELY NO WARRANTY.
 This is free software, and you are welcome to redistribute it
 under certain conditions (see <http://www.gnu.org/licenses/> 
 for details).
"""

USAGE_STRING = """
usage: %(scriptName)s -[flags] 
    where [flags] specify that source code is to be generated for any of:
        o - LibreOffice.org Calc addin
    or
        h - display this help message
"""


def usage():
    print(USAGE_STRING % { 'scriptName' : sys.argv[0] } )
    sys.exit(5)
 

    
def main():
    Logger().info("Entering main ...")

    # list of currently implemented code generators 
    addin_para_list = 'o'
    
    # parse command line arguments    
    try:
        opts, args = getopt.getopt(sys.argv[1:], addin_para_list+'h', ['help'])
    except getopt.GetoptError:
        usage()
        
    addin_id = ''
    for o, v in opts:
        if o=='-o':
            addin_id = 'o'
        if o=='-h' or o=='help':
            usage()
            sys.exit(0)
            
    if len(addin_id)==0:
        usage()
        sys.exit(5)
        
    #print license information
    print(LICENSE)
    Logger().info(LICENSE)
        
    # reading gensrc configuration    
    gensrc_configuration = GensrcConfiguration('./')
        
    
    # generate source code for chosen target projects.        
    Logger().debug('Addin %s ' %  addin_id)
    Logger().debug('Calling AddinList ')
    
    addinList = AddinList(addin_id)
    addinList.generate()
    
    Logger().info("Finished main ...")


    

if __name__ == "__main__":
    main()
    
    
