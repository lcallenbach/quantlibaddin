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


from code.addin.calc import CalcAddin
from code.configuration.gensrcconfiguration import GensrcConfiguration
from code.configuration.parsemetadata import ParseMetaData
from code.logging.logger import Logger



class AddinList(object):
    """Class to call relevant addin generation class.
        
    Variables:
        addin: List of addin which should be generated.
    """    
    
    creators = {
        'o' : (CalcAddin, 'Calc'),
    }

    def __init__(self, addin_id):
        """Constructor.
        
        Sets variable self.addins.
        """
        self.addin = {}

        config_path = GensrcConfiguration().configPath
        metadata_path = GensrcConfiguration().metadataPath

        Logger().debug('metadata path: '+metadata_path)
        Logger().debug('config path:   '+config_path)

        if len(addin_id)>0:
            creator, suffix = AddinList.creators[addin_id]
            Logger().info('start reading data for addin %s' % suffix)

            metadata = ParseMetaData(metadata_path, suffix)
            self.addin[suffix] = creator(config_path, suffix, metadata)

            Logger().info('end reading data for addin %s' % suffix)
           

    def generate(self):
        """Procedure that calls geneartors of addin.
        """
        for addin in list(self.addin.keys()):
            Logger().info('start generating code for addin %s' % addin)
            self.addin[addin].generate()
            Logger().info('AddinList: end generating code for addin %s' % \
                addin)
        