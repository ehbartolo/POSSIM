/* 
Software License Agreement (BSD License)

Copyright (c) 2013, Julian de Hoog <julian@dehoog.ca>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided
   with the distribution.
 * The name of the author may not be used to endorse or promote 
   products derived from this software without specific prior 
   written permission from the author.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. 
*/

#ifndef MATLABINTERFACE_H
#define	MATLABINTERFACE_H

#include <stdio.h>  /* defines FILENAME_MAX */


#include <iostream>
#include <sstream>
#include <vector>

#include "engine.h"

#include <boost/filesystem.hpp>

#include "LoadFlowInterface.h"
#include "../utility/Utility.h"

#define BUFSIZE 256

//const std::string matlabBinary = "/Applications/MATLAB_R2012a.app/bin";
    
class MatlabInterface : public LoadFlowInterface {
    
private:
    Engine *eng;
    mxArray *result;

    std::string modelDir;
    std::string modelName;
        
    std::stringstream ss;
    
public:
    MatlabInterface(std::string modelname);
    ~MatlabInterface();

    void setDir(std::string dir);
    void loadModel(std::string model);
    void runSim();
    double getVar(std::string var);
    void setVar(std::string component, double value, std::string var);
    int getNumHouses();
    std::vector <std::string> getHouseNames();
    void addVehicle(Vehicle vehicle);
    void setDemand(std::string component, double a, double i, double c);
    void printModel(std::string targetDir);
    void generateReport(std::string dir, int month, bool isWeekday, int simInterval);
    void getOutputs(double phaseV[12], double phaseI[12], double eolV[12], std::map<int, Household> &households);
};

#endif	/* MATLABINTERFACE_H */

