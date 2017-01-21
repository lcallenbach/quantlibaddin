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


from abc import ABCMeta, abstractmethod



class CodeGeneration(metaclass=ABCMeta):
    """Class with code generation helpers. 
    
    Provides the abstract methods generate_cpp() and generate_hpp(). Code 
    generation will be done using text idention and idention shifts (using 
    the function shift_text()).
    
    Code will be stored for each code line in the tuple 
    (#idention, code-text). Code-text is the real code, #idention determines
    the idention. 

    Variables:
        ident_txt: List of text identions (currently two blanks are used for 
            one idention)
    """    
        
    def __init__(self):
        self.ident_txt = []
        text = ''
        for i in range(12):
            self.ident_txt.append(text)
            text += '    '
    
        
    def get_addintype(self, class_name):
        """Function to convert constructor class to text.
        
        This function is used to replace '::' and '<'/'>' to text which can
        be used for class definitions. In the addin code the class references 
        in metadata are converted to text using this function.
        
        Arguments:
            class_name: Class name of constructor.
            
        Return:
            Text (converted class name)
        """
        text = class_name.replace('::', '_')
        text = text.replace('<', 'Z_')
        text = text.replace('>', '_Z')
        return text
        
    
    def shift_text(self, shift, lines):
        """Function to add idents to text.
        
        The parameter shift determines how many further code identions should
        be applied to the code.
        
        Argument:
            shift: Number of further identions.
            lines: List of code of format (#idention, code-text).
            
        Return:
            New code text with further identions (number of further identaions
            is given by parameter shift).
        """
        new = []
        for (ident, text) in lines:
            new.append( (ident+shift, text) )
        return new
        
    
    def get_text(self, lines):
        """Function to convert code in text.
        
        Code is given by a list of tuples (idention, code-text). The code 
        will be converted to text.
        
        Argument:
            lines: List of code text (tuple (#idention, code-text)).
            
        Return:
            Code as text.
        """
        all_text = ''
        for (ident, text) in lines:
            all_text += self.ident_txt[ident]+text+'\n'
        return all_text
                    
            
    @abstractmethod
    def generate_cpp(self):
        """Abstract method for cpp code generation.
        """
        return None
        
            
    @abstractmethod
    def generate_hpp(self):
        """Abstract method for hpp code generation.
        """
        return None
        
        