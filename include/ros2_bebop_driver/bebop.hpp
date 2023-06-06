/**
Software License Agreement (BSD)

\file      bebop.hpp
\authors   Jeremy Fix <jeremy.fix@centralesupelec.fr>
\copyright Copyright (c) 2022, CentraleSupélec, All rights reserved. Based on
the work of Mani Monajjemi bebop_autonomy

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.
 * Neither the name of Autonomy Lab nor the names of its contributors may be
used to endorse or promote products derived from this software without specific
prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WAR- RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, IN- DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

extern "C" {
#include <libARController/ARCONTROLLER_Device.h>
#include <libARDiscovery/ARDiscovery.h>
#include <libARSAL/ARSAL.h>
}

#include <string>
#include <type_traits>

namespace bebop_driver {
class Bebop {
   private:
    ARSAL_Sem_t stateSem;
    ARDISCOVERY_Device_t* device = nullptr;
    ARCONTROLLER_Device_t* deviceController = nullptr;
    bool is_connected = false;

   public:
    Bebop();
    ~Bebop();
    void connect(const std::string& bebop_ip);
    void takeOff(void);
    void land(void);
    void emergency(void);
    void flatTrim(void);
    void navigateHome(bool start_stop);
    void animationFlip(uint8_t anim_id);
    void move(double roll, double pitch, double gaz_speed, double yaw_speed);
    void moveCamera(double titl, double pan);

    void throwOnInternalError(const std::string& message);
    void throwOnCtrlError(const eARCONTROLLER_ERROR& error,
			  const std::string& message);
};
}  // namespace bebop_driver