# LibreOffice QuantLib Addin
LibreOffice-Calc QuantLib Addin

This document provides first steps with<br />
  1. code generation
  2. code compilation

This code has been tested for QuantLib-1.9.1 under Linux using Anaconda3 and 
LibreOffice 5.2. <br />
<br />

# code generation
Change to the directory gensrc. Execute 'python main.py -o'. <br />
Requirements:<br />
  1. Python 3
  2. PyParsing package

Both requirements are met using Anaconda3. <br />

# code compilation
Change to the directory 'Calc'. Edit the file 'environment.sh' -
the meaning of the variables is the following:<br />
  1. L_PATH: path to your QuantLib source code (e.g. QL_PATH=/test/QuantLib)
  2. QL_LIB: path to the compiled QuantLib library (e.g. QL_LIB=/test/QuantLib/ql/.libs)
  3. BOOST_PATH: path to your boost development installation (header files, depending 
       on your system)
       
In order to compile the files genereated you have to include the path variables (e.g.
execute '. environment.sh' under Gnu/Linux-bash). Include the LibreOffice SDK development 
setup to your path (e.g. execute '. ~/libreoffice/sdk/setsdkenv_unix.sh' under Gnu/Linux-bash).
If both paths are set call 'make' (for parallel execution of 4 processes call 'make -j4'). <br />


If you have used the auto-installation feature of the LibreOffice SDK nothing else has to 
be done. You can open the test sheet 'test.ods' by executing 'soffice path/test.ods'. <br />
Requirements: <br />
  1. installation of LibreOffice SDK 
  2.. development files for boost and compiled boost libraries (boost_regex, boost_serialization, lboost_filesystem, lboost_system)
  3. QuantLib library and QuantLib header files 
  4. C++ compiler (e.g. g++ under Gnu/Linux)

# license
The python code us under GNU General Public License version 3. The major part of the 
C++ code in the Calc/, oh/ and qlo/ directory are under QuantLib license. Some files 
are under BSD license (e.g. the Makefile in Calc/). For these licenses see e.g. <br />
  1. <http://www.gnu.org/licenses/>
  2. <http://quantlib.org/license.shtml>

