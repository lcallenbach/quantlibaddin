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


from code.codegeneration.codegeneration import CodeGeneration



class AddinClasses(CodeGeneration):
    """Class to generate code for constructors and member functions. 
    
    Provides the implementation of the two functins generate_cpp() and 
    generate_hpp() for objects with constructors or member functions. 

    Variables:
        constructors: Constructors (from parsemetadata.py)
        conversions: Conversions (from parsemetadata.py)
        memberfunctions: MemberFunctions (from parsemetadata.py)
        default_class: Default class for objects managed by ObjectHandler (e.g.
            std::string)
        prefix: Prefix for variables (e.g. 'IDL_')
        idl_suffix: Suffix for idl variables (e.g. '_any' for Calc)
        enumerations: Enumerations (from parsemetadata.py)
        template_arguments: Template arguments (from parsemetadata.py)
        functions: Functions (from parsemetadata.py)
        suffix: Suffix for C++ variables (after conversion from IDL)
    """    
       
    def __init__(self, constructors, conversions, memberfunctions, \
                     default_class, prefix, enumerations, template_arguments, \
                     functions, idl_suffix):
        CodeGeneration.__init__(self)
        self.conversions = conversions
        self.constructors = constructors
        self.memberfunctions = memberfunctions
        self.default_class = default_class
        self.prefix = prefix
        self.idl_suffix = idl_suffix
        self.enumerations = enumerations
        self.template_arguments = template_arguments
        self.functions = functions
        
        self.suffix = '_cpp'

        
    def generate_cpp(self):
        """Implementation of the abstract class for cpp code generation.
        
        This function generates the C++-cpp code for the addin classes.
        
        Return:
            List of code lines of type Tuple(idention, code text).
        """
        lines = []
        processed = set()
        actual_class = ''

        # constructors
        for key1 in self.constructors.keys():
            constr = self.constructors[key1][0]
            constr_class = constr.get_classname()
            if not (constr_class in processed):
                actual_class = constr_class
                processed.add( actual_class )                
                constr_addintype = self.get_addintype(constr_class)
                
                addin_classname = self.get_addintype(actual_class)
                line = (0, 'class %sError: public std::exception {' % \
                        addin_classname)
                lines.append(line)
                line = (1, 'const char * what () const throw () { ')
                lines.append(line)
                line = (2, 'return "Wrong template arguments for %s";' % \
                        actual_class)
                lines.append(line)
                line = (1, '};')
                lines.append(line)
                line = (0, '};')
                lines.append(line)

                lines.append((0, ''))
                update_code = []
                delete_code = []

                # iterate over all possible constructors using counter to  
                # distinguish between different constructors of same class
                counter = 0
                for key2 in self.constructors.keys():
                    constr = self.constructors[key2][0]
                    constr_class = constr.get_classname()
                    if constr_class==actual_class:
                        addin_name = key2.addin_name
                        line = '%s::%s' % (constr_addintype, \
                                self.generate_constr_declaration(constr))
                        lines.append((0, line))
                        line = ': ObjectHandler::Object(std::string("%s"))' %\
                                constr_addintype
                        lines.append((2, line))
                        code = self.generate_constr_body(constr, counter)
                        lines += self.shift_text(1, code)
                        update_code += self.generate_update_body(constr, \
                                addin_name, counter)
                        delete_code += self.generate_delete_body(constr, \
                                addin_name, counter)
                        counter += 1
                        
                # generate update() and del() methods
                lines.append((0, ''))
                line = 'void %s::update() {' % constr_addintype
                lines.append((0, line))
                line = 'del();'
                lines.append((1, line))
                lines += self.shift_text(1, update_code)
                lines.append((0, '};'))
                
                lines.append((0, ''))
                line = 'void %s::del() {' % constr_addintype
                lines.append((0, line))
                lines += self.shift_text(1, delete_code)
                line = 'object_ = (void *)(0L);'
                lines.append((1, line))
                lines.append((0, '};'))
                
                # generate member functions 
                for key2 in self.memberfunctions.keys():
                    mem_func_class = self.memberfunctions[key2][0]
                    mem_func_class = mem_func_class.get_classname()
                    if mem_func_class==actual_class:
                        mem_func = self.memberfunctions[key2][1]
                        line = '%s %s::%s' % (mem_func.get_returntype(), \
                                constr_addintype, \
                                self.generate_memfunc_declaration(mem_func))
                        lines.append((0, line))
                        code = self.generate_memfunc_body( \
                                mem_func, actual_class)
                        lines += self.shift_text(0, code)
                lines.append((0, ''))

        # member functions for classes without constructors (e.g. base classes)
        for key1 in self.memberfunctions.keys():
            mem_func_class = self.memberfunctions[key1][0]
            class_name = mem_func_class.get_classname()
            if not (class_name in processed):
                actual_class = class_name
                processed.add( actual_class )                
                constr_addintype = self.get_addintype(class_name)
                
                for key2 in self.memberfunctions.keys():
                    mem_func = self.memberfunctions[key2][0]
                    mem_func_class = mem_func.get_classname()
                    if mem_func_class==actual_class:
                        mem_func = self.memberfunctions[key2][1]
                        line = '%s %s::%s' % (mem_func.get_returntype(), \
                                constr_addintype, \
                                self.generate_memfunc_declaration(mem_func))
                        lines.append((0, line))
                        code = self.generate_memfunc_body( \
                                mem_func, actual_class)
                        lines += self.shift_text(0, code)
                lines.append((0, ''))

        # functions and procedures 
        for key in self.functions.keys():
            func = self.functions[key][1]
            line = '%s %s' % (func.get_returntype(), \
                              self.generate_func_declaration(func))
            lines.append((0, line))
            code = self.generate_func_body(func)
            lines += self.shift_text(0, code)
        lines.append((0, ''))
                
        return lines


    def generate_hpp(self):
        """Implementation of the abstract class for hpp code generation.
        
        This function generates the C++-hpp code for the addin classes.
        
        Return:
            List of code lines of type Tuple(idention, code text).
        """
        processed = set()
        actual_class = ''
        lines = []
        
        # constructors
        for key1 in self.constructors.keys():
            constr = self.constructors[key1][0]
            constr_class = constr.get_classname()
            if not (constr_class in processed):
                actual_class = constr_class
                processed.add( actual_class )                
                constr_addintype = self.get_addintype(constr_class)
                
                line = 'class %s : public ObjectHandler::Object {' % \
                        (constr_addintype)
                lines.append((0, line))
                line = 'std::vector<boost::any> arguments_;'
                lines.append((1, line))
                line = 'int method_;'
                lines.append((1, line))
                line = 'virtual void update();'
                lines.append((1, line))
                line = 'virtual void del();'
                lines.append((1, line))
                line = 'public:'
                lines.append((1, line))
                
                # list of constructors
                for key2 in self.constructors.keys():
                    constr = self.constructors[key2][0]
                    constr_class = constr.get_classname()
                    if constr_class==actual_class:
                        line = self.generate_constr_declaration(constr) + ';'
                        lines.append((1, line))
                
                # list of member function of the actual_class
                for key2 in self.memberfunctions.keys():
                    mem_func_class = self.memberfunctions[key2][0]
                    mem_func_class = mem_func_class.get_classname()
                    if mem_func_class==actual_class:
                        mem_func = self.memberfunctions[key2][1]
                        line = 'static %s %s;' % (mem_func.get_returntype(), \
                            self.generate_memfunc_declaration(mem_func))
                        lines.append((1, line))
                
                line = '//inline ~' + constr_addintype + '() { '
                lines.append((1, line))
                line = '//del(); '
                lines.append((2, line))
                line = '//}'
                lines.append((1, line))
            lines.append((0, '};'))
        
        # base classes and associated member functions
        for key1 in self.memberfunctions.keys():
            mem_func_class = self.memberfunctions[key1][0]
            class_name = mem_func_class.get_classname()
            if not (class_name in processed):
                actual_class = class_name
                processed.add( actual_class )
                
                constr_addintype = self.get_addintype(class_name)
                line = 'class ' + constr_addintype + ' {'
                lines.append((0, line))
                line = 'public:'
                lines.append((1, line))
                line = self.generate_constr_declaration(mem_func_class)+ ' {};'
                lines.append((1, line))
                
                for key2 in self.memberfunctions.keys():
                    mem_func = self.memberfunctions[key2][0]
                    mem_func_class = mem_func.get_classname()
                    if mem_func_class==actual_class:
                        mem_func = self.memberfunctions[key2][1]
                        line = 'static %s %s;' %( mem_func.get_returntype(), \
                            self.generate_memfunc_declaration(mem_func))
                        lines.append((1, line))
                lines.append((0, '};'))

        # functions and procedures 
        for key in self.functions.keys():
            func = self.functions[key][1]
            line = '%s %s;' % (func.get_returntype(), \
                              self.generate_func_declaration(func))
            lines.append((0, line))
            
        return lines
        
        
    def find_conversion(self, class_name):
        """Find a conversion for type class_name.
    
        Find an entry for class_name in the conversions generated. Uses 
        self.default_class as fallback type. 
        
        Parameters:
            class_name: Name of class to look for. 
            
        Returns:
            Named tuple Conversion (defined in parsemetadata.py).
        """
        typ = self.default_class
        if typ in self.conversions.keys():
            typ = self.conversions[typ]
        if class_name in self.conversions.keys():
            typ = self.conversions[class_name]

        return typ
        
        
    def generate_memfunc_declaration(self, memberfunction):
        """Function to generate code for the member function declaration.
        
        This function analyses the member function and returns the member 
        function declaration as text.
        
        Argument:
            memberfunction: MemberFunction to be anlysed.

        Return:
            Text with member function declaration. 
        """
        text = memberfunction.get_functionname()    
        if text=='operator()':
            text = 'addinOperator'
        parameter_list = memberfunction.get_parameters()
        text = text +  self.generate_param_declaration(parameter_list, False)
        return text
        
    
    def generate_func_declaration(self, function):
        """Function to generate code for the function declaration.
        
        This function analyses the member function and returns the member 
        function declaration as text.
        
        Argument:
            memberfunction: MemberFunction to be anlysed.

        Return:
            Text with member function declaration. 
        """
        text = self.get_addintype(function.get_functionname())
        parameter_list = function.get_parameters()
        text = text +  self.generate_param_declaration(parameter_list, True)
        return text

        
    def generate_constr_declaration(self, constructor):
        """Function to generate code for the constructor declaration.
        
        This function analyses the constructor and returns the constructor 
        declaration as text.
        
        Argument:
            constructor: Constructor to be anlysed.

        Return:
            Text with constructor declaration. 
        """
        class_name = self.get_addintype(constructor.get_classname()) 
        parameter_list = constructor.get_parameters()
        text = class_name + self.generate_param_declaration(parameter_list, 
                                                            True)
        return text

    
    def generate_param_declaration(self, parameter_list, excl_first_arg=False):
        """Function to generate parameter declaration code.

        This function analyses the parameters provided in parameter_list and
        generates the C++ code as text line for the parameters used in 
        constructors and member functions.
        
        Argument:
            parameter_list: List of Parameters. 
            excl_first_arg: Boolean flag to exclude first argument (object id). 
            
        Return:
            Text with parameters (one line in brackets).
        """
        text = '('
        found_parameter = False
        first_argument = True
        for parameter in parameter_list:
            if excl_first_arg and first_argument:
                first_argument = False
                continue

            class_name = parameter.get_classname()
            conv = self.find_conversion(class_name)
            typ = self.prefix + conv.idl
            typ = self.prefix + 'any'
            variable_name = parameter.get_variablename()+self.idl_suffix
            dimension = parameter.get_dimension()
            if not (conv.flag is None) and (conv.flag==1 or conv.flag==2):
                dimension = conv.flag
            dimension_text = ''
            if dimension>0:
                dimension_text = 'SEQSEQ('
            text = text + dimension_text + typ 
            if dimension>0:
                text = text + ')'
            text = text + ' ' 
            text = text + variable_name + ', '
            found_parameter = True

        if found_parameter:
            text = text[:-2]

        text = text + ')'
        
        return text 
        
    
    def generate_param_body(self, parameter_list, excl_first_arg=False, 
                ignore_in_arg_list=False, templateargs=[], 
                in_memfunc=False, template_args_only=False):
        """Function to generate parameter conversion code body.
        
        This function generates the C++ code for parameters provided in the
        parameter_list. Conversion of parameters will be delegated to the 
        functions _para_conv_type, _para_conv_enumerated_object and 
        _para_conv_object. 
        
        For each parameter the idea is to lool wheter it is an enumerated type 
        or an plain vanilla type defined by a conversion. If neither is true 
        the parameter will be treated as an object (based on a constructor and
        stored in the ObjectHandler). 
        
        This function provides a list of the parameters that are converted in
        C++ style. This list can be used as arguments for the code generation 
        of e.g. member functions.
        
        Argument:
            parameter_list: List of Parameters. 
            excl_first_arg: Boolean flag to ignoer first argument (object name).
            ignore_in_arg_list: first argument will be ignored in parameter 
                list which will be returned. 
            template_args: List of name of template arguments.
            in_memfunc: Boolean flag to indicate member functions. If the first
                argument should not be treated as an object in this code part. 
                In generate_memfunc_body() the right conversion will be done. 
                A string should be provided for the ObjectHandler. 
            template_args_only: Boolean flag for generate_delete_body().
        
        Return:
            Tuple of (list of code, C++ parameter list as text) 
        """
        argument_list = ''
        first_argument = True

        lines = []
        lines.append((0, ''))
        line = '// parameter conversions '
        lines.append((0, line))
        
        first_para = True
        for parameter in parameter_list:
            if excl_first_arg and first_argument:
                first_argument = False
                continue
            
            if not ( parameter.get_variablename() in templateargs ) and \
              template_args_only==True:
                continue

            class_name = parameter.get_classname()
            conv = self.find_conversion(class_name)
            typ_cpp = conv.cpp

            is_object = False
            is_enum_object = False
            if self._is_enumerated_object(class_name):
                is_enum_object = True
            else:
                if typ_cpp==self.default_class:
                    is_object = True
            
            if first_para and in_memfunc==True:
                is_object = False
                first_para = False
            
            var_name = parameter.get_variablename()
            if var_name in templateargs:
                is_object = False
            
            if is_object:
                code = self._para_conv_object(class_name, parameter)
                lines += self.shift_text(0, code)
            else: 
                if is_enum_object:
                    code = self._para_conv_enumerated_object(class_name, \
                            parameter)
                    lines += self.shift_text(0, code)
                else:
                    code = self._para_conv_type(class_name, parameter)
                    lines += self.shift_text(0, code)
                    
            if ignore_in_arg_list and first_argument:
                first_argument = False
                continue
            
            if parameter.get_variablename() in templateargs:
                continue
                        
            var_name = parameter.get_variablename()
            argument_list = argument_list + ', ' + var_name + self.suffix
        if len(argument_list)>1:
            argument_list = argument_list[2:]
            
        return (lines, argument_list)
        
    
    def generate_memfunc_body(self, memfunc, memfunc_class):
        """Function to generate member function code body.
        
        This function generates the C++ code for member functions. It calls the
        function generate_param_body() to get the C++ variables for the 
        provided parameters. The code for enumerated types and constructors is
        different. Code for enumearted types will be provided by the addin 
        (enumeratedobjects.py). 
        The function handels calls of the C++ operator(). If converts the 
        object to the necessary type (e.g. downcast from QuantLib::ZeroCurve to
        QuantLib::YieldTermStructure) and calls the member function if it is 
        not an enumerated type.
        
        Argument:
            memfunc: MemberFunction argument to be analysed.
            memfunc_class: Class of member function. 
        
        Return:
            List of code.
        """
        lines = []
        
        line = '{'
        lines.append((0, line))
        
        parameter_list = memfunc.get_parameters()
        (code, argument_list) = \
            self.generate_param_body(parameter_list, False, True, [], True)

        lines += self.shift_text(1, code)
        lines.append((0, ''))
        
        is_enum_object = False
        if self._is_enumerated_object(memfunc_class):
            is_enum_object = True

        if is_enum_object:
            var_name = 'ObjectIdEnum_cpp'
            conv_func = self.get_addintype(memfunc_class)+'Enum'
            line = '// convert enumerated type'
            lines.append((1, line))
            line = memfunc_class + ' ' + var_name + ';'
            lines.append((1, line))
            line = 'scalarInterfaceToCpp(ObjectId, %s, %s);' % \
                    (var_name, conv_func)
            lines.append((1, line))

            line = '// return value   \n'
            lines.append((1, line))
            line = 'return %s.%s(%s);' % \
                    (var_name, memfunc.get_functionname(), argument_list)
            lines.append((1, line))
        else:
            line = '// convert object reference'
            line = '%s *ObjectId_ref = (static_cast<%s *>'
            line += '(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()));'
            line = line % (memfunc_class, memfunc_class)
            lines.append((1, line))
            
            line = '// return value  '
            lines.append((1, line))
            if memfunc.get_functionname()=='operator()':
                line = 'return (*ObjectId_ref)(%s);' % ( argument_list)
            else:
                line = 'return ObjectId_ref->%s(%s);' % \
                        (memfunc.get_functionname(), argument_list) 
            lines.append((1, line))

        line = '};'
        lines.append((0, line))
        line = ''
        lines.append((0, line))
        
        return lines        
        
    
    def generate_func_body(self, func):
        """Function to generate function code body.
        
        This function generates the C++ code for member functions. It calls the
        function generate_param_body() to get the C++ variables for the 
        provided parameters.  
        
        Argument:
            func: MemberFunction argument as function to be analysed.
        
        Return:
            List of code.
        """
        lines = []
        
        line = '{'
        lines.append((0, line))
        
        parameter_list = func.get_parameters()
        (code, argument_list) = \
            self.generate_param_body(parameter_list, True, True, [], True)

        lines += self.shift_text(1, code)
            
        line = '// return value  '
        lines.append((1, line))
        line = 'return %s(%s);' % \
                    (func.get_functionname(), argument_list) 
        lines.append((1, line))
        line = '};'
        lines.append((0, line))
        line = ''
        lines.append((0, line))
        
        return lines        
        
        
    def generate_delete_body(self, constructor, addin_name, counter):
        """Function to generate del() code body for constructor.
        
        This function generates the C++-del() body. It converts the values
        of the C++-variable arguments_ from the type boost::any to the relevant
        C++-type (e.g. double) using the function generate_param_body(). This 
        is necessary to find out the template arguments. 
        After creation of the relevant variables the C++-variable object_ will
        be deleted - the code will be set for templates in a cross-product 
        fashion. 
        
        Argument:
            constructor: Constructor argument to be analysed.
            addin_name: Name of addin in Calc
            counter: Integer counter to distinguish different constructors. 
        
        Return:
            List of code.
        """
        parameter_list = constructor.get_parameters()
        parameter_list = parameter_list[1:]

        lines = []
        line = 'if (method_==%d) {' % counter
        lines.append((0, line))
        line = '// convert back from boost::any'
        lines.append((1, line))
        
        index = 0
        template_args = constructor.get_templateargs()
        for parameter in parameter_list:
            
            if template_args and not (parameter.get_variablename() in template_args):
                continue
            
            class_name = parameter.get_classname()
            conv = self.find_conversion(class_name)
            typ_idl = self.prefix + conv.idl
            typ_idl = self.prefix + 'any'
            var_name = parameter.get_variablename()

            dimension = parameter.get_dimension()
            if conv.flag is not None and (conv.flag==1 or conv.flag==2):
                dimension = conv.flag
                
            dimension_text = ''
            if dimension>0:
                dimension_text += 'SEQSEQ('
            dimension_text += typ_idl
            if dimension>0:
                dimension_text += ')'
            line = dimension_text + ' '+  var_name + self.idl_suffix + ';'
            lines.append((1, line))
            
            line = '%s = boost::any_cast<%s >(arguments_[%s]);' % \
                (var_name+self.idl_suffix, dimension_text, index)                
            lines.append((1, line))

            index += 1

            templ_args = constructor.get_templateargs()

        
        argument_list = ''
        (code, argument_list) = self.generate_param_body(parameter_list, \
                                    False, False, \
                                    [] if template_args==None else template_args,
                                    False, True)
        lines += self.shift_text(1, code)
        
        class_name = constructor.get_classname()
        lines.append((1, 'if(!object_) return;'))
        line = '// delete addin object'
        lines.append((1, line))
        if constructor.get_templateargs() is None:   # no template argument
            line = 'delete (%s *)(object_);' % (class_name)
            lines.append((1, line))
        else:   # template arguments
            templ_args = constructor.get_templateargs()
            
            """Code for template evaluation.            
            A recursive code generation call for multiple template parameters.
            """
            def _code_recursive(templ_args, templ_txt, depth):
                lines = []
                if not templ_args:
                    line = 'delete (%s<%s>*)(object_);' % \
                        (class_name, templ_txt)
                    lines.append((0+depth, line))
                else:
                    name = templ_args[0]
                    for templ in self.template_arguments:
                        templ_name = templ.name
                        
                        if templ_name==name and templ.addin_name==addin_name:
                            var_name = templ_name + self.suffix
                            typ_cpp = templ.cpp
                            var_arg = templ.arg
                            fill = ''
                            if typ_cpp=='std::string':
                                fill = '"'
                            line = 'if(%s==%s(%s%s%s)) { ' % \
                                (var_name, typ_cpp, fill, var_arg, fill)
                            lines.append((0+depth, line))

                            txt_len = 0
                            if len(templ_txt)<1:
                                templ_txt = templ.value
                                txt_len = len(templ.value)
                            else:
                                templ_txt += ',' + templ.value
                                txt_len = len(templ.value)+1
                            lines += _code_recursive(templ_args[1:], \
                                                     templ_txt, depth+1)            
                            templ_txt = templ_txt[:-txt_len]
                            line = '};'
                            lines.append((0+depth, line))
                return lines
            
            lines += _code_recursive(templ_args, '', 1)

        lines.append((0, '}'))
        
        return lines            
                
    
    def generate_update_body(self, constructor, addin_name, counter):
        """Function to generate update() code body for constructor.
        
        This function generates the C++-update() body. It converts the values
        of the C++-variable arguments_ from the type boost::any to the relevant
        C++-type (e.g. double) using the function generate_param_body(). 
        After creation of the relevant variables the C++-variable object_ will
        be set - the code will be generated for templates in a cross-product 
        fashion. 
        
        Argument:
            constructor: Constructor argument to be analysed.
            addin_name: Name of addin (i.e. invocation name in Calc)
            counter: Integer counter to distinguish different constructors. 
        
        Return:
            List of code.
        """
        parameter_list = constructor.get_parameters()
        parameter_list = parameter_list[1:]

        lines = []
        line = 'if (method_==%d) {' % counter
        lines.append((0, line))
        line = '// convert back from boost::any'
        lines.append((1, line))
        line = 'std::cerr << "in upate() von %s" << std::endl;' % constructor.get_classname()
        lines.append((1, line))
        
        index = 0
        for parameter in parameter_list:    
            class_name = parameter.get_classname()
            conv = self.find_conversion(class_name)
            typ_idl = self.prefix + conv.idl
            typ_idl = self.prefix + 'any'
            var_name = parameter.get_variablename()

            dimension = parameter.get_dimension()
            if conv.flag is not None and (conv.flag==1 or conv.flag==2):
                dimension = conv.flag
                
            dimension_text = ''
            if dimension>0:
                dimension_text += 'SEQSEQ('
            dimension_text += typ_idl
            if dimension>0:
                dimension_text += ')'
            line = dimension_text + ' '+  var_name + self.idl_suffix + ';'
            lines.append((1, line))
            
            line = '%s = boost::any_cast<%s >(arguments_[%s]);' % \
                (var_name+self.idl_suffix, dimension_text, index)                
            lines.append((1, line))

            index += 1
            
        argument_list = ''
        template_args = constructor.get_templateargs()
        (code, argument_list) = self.generate_param_body(parameter_list, \
                                    False, False, \
                                    [] if template_args==None else template_args)
        lines += self.shift_text(1, code)
        
        class_name = constructor.get_classname()
        line = '// create addin object'
        lines.append((1, line))
        if constructor.get_templateargs() is None:   # no template argument
            line = 'object_ = (void *)(new %s(%s));' % \
                (class_name , argument_list)
            lines.append((1, line))
        else:   # template arguments
            templ_args = constructor.get_templateargs()
            
            """Code for template evaluation.            
            A recursive code generation call for multiple template parameters.
            """
            def _code_recursive(templ_args, templ_txt, depth):
                lines = []
                if not templ_args:
                    line = 'object_ = (void *)(new %s<%s>(%s));' % \
                        (class_name, templ_txt, argument_list)
                    lines.append((0+depth, line))
                    line = 'found = true;'
                    lines.append((0+depth, line))                    
                else:
                    name = templ_args[0]
                    for templ in self.template_arguments:
                        templ_name = templ.name

                        if templ_name==name and templ.addin_name==addin_name:
                            var_name = templ_name + self.suffix
                            typ_cpp = templ.cpp
                            var_arg = templ.arg
                            fill = ''
                            if typ_cpp=='std::string':
                                fill = '"'
                            line = 'if(%s==%s(%s%s%s)) { ' % \
                                (var_name, typ_cpp, fill, var_arg, fill)
                            lines.append((0+depth, line))

                            txt_len = 0
                            if len(templ_txt)<1:
                                templ_txt = templ.value
                                txt_len = len(templ.value)
                            else:
                                templ_txt += ',' + templ.value
                                txt_len = len(templ.value)+1
                            lines += _code_recursive(templ_args[1:], \
                                                     templ_txt, depth+1)            
                            templ_txt = templ_txt[:-txt_len]
                            line = '};'
                            lines.append((0+depth, line))
                return lines            
            
            line = (1, 'bool found=false;')
            lines.append(line)
            lines += _code_recursive(templ_args, '', 1)

            addin_classname = self.get_addintype(class_name)
            line = (1, 'if(not found) throw %sError();' % addin_classname)
            lines.append(line)

        lines.append((0, '}'))
        lines.append((0, ''))
        
        return lines    
        
        
    def generate_constr_body(self, constructor, counter):
        """Function to generate constructor code body.
        
        This function generates the constructor body. It stores the provided
        parameters in the C++-arguments_ variable and calls the C++
        update() function.
        
        Argument:
            constructor: Constructor argument to be analysed.
            counter: Integer counter to distinguish different constructors. 
        
        Return:
            List of code.
        """
        lines = []

        line = '{'
        lines.append((0, line))
        line = '// set constructor method'
        lines.append((1, line))
        line = 'object_ = 0L;'
        lines.append((1, line))
        line = 'method_ = %d;' % counter
        lines.append((1, line))
        lines.append((1, ''))
        
        parameter_list = constructor.get_parameters()
        parameter_list = parameter_list[1:]
        
        line = '// store parameters '        
        lines.append((1, line))
        for parameter in parameter_list:    
            variable_name = parameter.get_variablename()
            line = 'arguments_.push_back(%s);' % (variable_name+self.idl_suffix)
            lines.append((1, line))

        lines.append((1, ''))
        line = '// call update to create object'        
        lines.append((1, line))
        line = 'update();'
        lines.append((1, line))

        line = '};'
        lines.append((0, line))
        
        return lines
         
        
    def _para_conv_enumerated_object(self, class_name, parameter):
        """Function to generate parameter conversion for enumerated objects.
        
        This function converts enumerated objects. The conversion function 
        for enumerated objects is of a special name and will be dynamically 
        generated by code (in enumeratedobjects.py).
        
        Argument:
            class_name: Name of class to look for in conversions.
            parameter: Parameter argument to be analysed.
        
        Return:
            List of code.
        """
        dimension = parameter.get_dimension()
        var_name = parameter.get_variablename()
        suffix = self.suffix
        
        conv = self.find_conversion(class_name)
        typ_idl = self.prefix + conv.idl
        
        typ_cpp = class_name
        conv_func = self.get_addintype(parameter.get_classname())+'Enum'
        
        lines = []
        if dimension==0:
            line = '%s %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = '%s %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'if(%s.hasValue()) { ' % (var_name+self.idl_suffix)
            lines.append((0, line))
            line = 'scalarAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((1, line))
            line = 'scalarInterfaceToCpp(%s, %s, %s);' % \
                    (var_name, var_name+suffix, conv_func)
            lines.append((1, line))
            if parameter.default_value is not None:
                line = '} else { '
                lines.append((0, line))
                line = '%s = %s; ' % (var_name+suffix, parameter.default_value)
                lines.append((1, line))
            line = '}'            
            lines.append((0, line))
        if dimension==1:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'vectorAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((0, line))
            line = 'std::vector<%s> %s;' % \
                    (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'vectorInterfaceToCpp(%s, %s, %s);' % \
                    (var_name, var_name+suffix, conv_func)
            lines.append((0, line))
        if dimension==2:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'matrixAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((0, line))
            line = 'std::vector<std::vector<%s> > %s;' % \
                    (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'matrixInterfaceToCpp(%s, %s, %s);' % \
                    (var_name, var_name+suffix, conv_func)
            lines.append((0, line))
        lines.append((0, ''))
        
        return lines

        
    def _para_conv_object(self, class_name, parameter):
        """Function to generate parameter conversion for repository objects.
        
        This function converts objects of the repository to the required data 
        type (e.g. QuantLib::YieldTermStructure). The conversion from pointers
        to boost::shared_ptr or QuantLib::Handle will also be done by 
        appropriate helper functions. 
        
        Argument:
            class_name: Name of class to look for in conversions.
            parameter: Parameter argument to be analysed.
        
        Return:
            List of code.
        """
        dimension = parameter.get_dimension()
        var_name = parameter.get_variablename()
        suffix = self.suffix
        
        typ_cpp = class_name
        if parameter.is_handle:
            typ_cpp = 'QuantLib::Handle<'+class_name+' > '
        if parameter.is_sharedptr:
            typ_cpp = 'boost::shared_ptr<' + class_name + ' > '     
        conv = self.find_conversion(class_name)
        conv_func = conv.fromidl
        typ_idl = self.prefix + conv.idl

        lines = []
        if dimension==0:
            line = '%s %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = '%s %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'if(%s.hasValue()) { ' % (var_name+self.idl_suffix)
            lines.append((0, line))
            line = 'scalarAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((1, line))
            if self._is_templatearg(var_name):
                line = 'scalarInterfaceToCpp(%s, %s, %s);' % \
                        (var_name, var_name+suffix, conv_func)
            else: 
                line = None
                if parameter.is_handle:
                    line = 'scalarObjectHandle(%s, %s); ' % \
                        (var_name, var_name+suffix)
                if parameter.is_sharedptr:
                    line = 'scalarObjectSharedPtr(%s, %s); ' % \
                        (var_name, var_name+suffix)
                if line is None:
                    line = 'scalarObject(%s, %s); ' % \
                        (var_name, var_name+suffix)
            lines.append((1, line))
            if parameter.default_value is not None:
                line = '} else { '
                lines.append((0, line))
                line = '%s = %s; ' % (var_name+suffix, parameter.default_value)
                lines.append((1, line))
            line = '}'            
            lines.append((0, line))
        if dimension==1:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'vectorAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((0, line))
            line = 'std::vector<%s > %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            if self._is_templatearg(var_name):
                line = 'vectorInterfaceToCpp(%s, %s, %s);' % \
                        (var_name, var_name+suffix, conv_func)
            else: 
                line = None
                if parameter.is_handle:
                    line = 'vectorObjectHandle(%s, %s); ' % \
                        (var_name, var_name+suffix)
                if parameter.is_sharedptr:
                    line = 'vectorObjectSharedPtr(%s, %s); ' % \
                        (var_name, var_name+suffix)
                if line is None:
                    line = 'vectorObject(%s, %s); ' % \
                        (var_name, var_name+suffix)
            lines.append((0, line))
        if dimension==2:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'matrixAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((0, line))
            line = 'std::vector<std::vector<%s > > %s;' % \
                    (typ_cpp, var_name+suffix)
            lines.append((0, line))
            if self._is_templatearg(var_name):
                line = 'matrixInterfaceToCpp(%s, %s, %s);' % \
                        (var_name, var_name+suffix, conv_func)
            lines.append((0, line))
        lines.append((0, ''))
        
        return lines
        
    
    def _para_conv_type(self, class_name, parameter):
        """Function to generate parameter conversion for 'normal' data types.
        
        This function converts plain vanilla data types (long, double etc.). 
        Special types are also handles (e.g. QuantLib::Matrix). The idea is 
        to look for a simple type. If it is simple then the conversion will 
        be done using scalar, vector or matrix conversions (using multi-
        dimensional arrays of type std::vector). If it is not a simple type
        the conversion function of parameter.conversions will be used. 
        
        Argument:
            class_name: Name of class to look for in conversions.
            parameter: Parameter argument to be analysed.
        
        Return:
            List of code.
        """
        dimension = parameter.get_dimension()
        var_name = parameter.get_variablename()
        suffix = self.suffix

        simple_type = True
        conv = self.find_conversion(class_name)
        typ_cpp = conv.cpp                
        conv_func = conv.fromidl
        typ_idl = self.prefix + conv.idl
        if conv_func=='Default':
            conv_func = 'interfaceToIdentity'
        if not (conv.flag is None) and (conv.flag==1 or conv.flag==2):
            dimension = conv.flag
            typ_cpp = conv.typ
            simple_type = False
            
            
        if var_name=='InterpolatorID' and (dimension!=0 or not simple_type):
            print(dimension, simple_type)
            sys.exit(5)

        lines = []
        line = ''
        
        if not simple_type:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = '%s %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'if(%s.getLength()>0) { ' % (var_name+self.idl_suffix)
            lines.append((0, line))
            line = 'vectorAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((1, line))
            conv_line = '%s(%s, %s);' % \
                        (conv_func, var_name, var_name+suffix)
            lines.append((1, conv_line))                
            if parameter.default_value is not None:
                line = '} else { '
                lines.append((0, line))
                line = '%s = %s; ' % (var_name+suffix, parameter.default_value)
                lines.append((1, line))
            line = '}'            
            lines.append((0, line))

        if simple_type and dimension==0:
            line = '%s %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = '%s %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'if(%s.hasValue()) { ' % (var_name+self.idl_suffix)
            lines.append((0, line))
            line = 'scalarAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((1, line))
            conv_line = 'scalarInterfaceToCpp(%s, %s, %s);' % \
                        (var_name, var_name+suffix, conv_func)
            lines.append((1, conv_line))                 
            if parameter.default_value is not None:
                line = '} else { '
                lines.append((0, line))
                line = '%s = %s; ' % (var_name+suffix, parameter.default_value)
                lines.append((1, line))
            line = '}'            
            lines.append((0, line))
            
        if simple_type and dimension==1:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'std::vector<%s> %s;' % (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'if(%s.getLength()>0) { ' % (var_name+self.idl_suffix)
            lines.append((0, line))
            line = 'vectorAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((1, line))
            line = 'vectorInterfaceToCpp(%s, %s, %s);' % \
                    (var_name, var_name+suffix, conv_func)
            lines.append((1, line))
            if parameter.default_value is not None:
                line = '} else { '
                lines.append((0, line))
                line = '%s = %s; ' % (var_name+suffix, parameter.default_value)
                lines.append((1, line))
            line = '}'            
            lines.append((0, line))
        if simple_type and dimension==2:
            line = 'SEQSEQ(%s) %s;' % (typ_idl, var_name)
            lines.append((0, line))
            line = 'matrixAnyToIDL(%s, %s);' % \
                    (var_name+self.idl_suffix, var_name)   
            lines.append((0, line))
            line = 'std::vector<std::vector<%s> > %s;' % \
                    (typ_cpp, var_name+suffix)
            lines.append((0, line))
            line = 'matrixInterfaceToCpp(%s, %s, %s);' % \
                    (var_name, var_name+suffix, conv_func)
            lines.append((0, line))
        lines.append((0, ''))
        
        return lines

        
    def _is_enumerated_object(self, class_name):
        """Function to look for class_name in enumerated objects.
    
        Identify whether class_name is an enumerated object.
            
        Returns:
            True, if enumerated object type (else False).
        """
        for key in self.enumerations:
            if class_name==self.enumerations[key]:
                return True
        return False
        
        
    def _is_templatearg(self, name):
        """Function to look for name in template arguments.
        
        Argument:
            name: Name of parameter.
            
        Return:
            True if name is template argument (else False)
        """
        for templ_arg in self.template_arguments:
            if templ_arg.name==name:
                return True
            return False
        
        
        
        
if __name__ == "__main__":
    import sys, os
    sys.path.append(os.path.join(sys.path[0], '..', '..'))
    from code.configuration.parsemetadata import ParseMetaData
    
    pmd = ParseMetaData('/work/QuantLib-Addin/gensrc/metadata', 'Calc')
    print(pmd.all_types)
    print(pmd.all_conversions)
