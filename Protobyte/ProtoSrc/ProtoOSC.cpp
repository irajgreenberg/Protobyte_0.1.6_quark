/*!  \brief  ProtoOSC.cpp: OSC implementation
 ProtoOSC.cpp
 Protobyte Library v02
 
 Created by Ira on 2/17/18.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#include "ProtoOSC.h"


#include <iostream>
#include "OSCReceiver.h"
//#include "Toroid.h"


OSCReceiver::OSCReceiver() { }

OSCReceiver::OSCReceiver(const char* address, Abacus* abacus):
address(address), abacus(abacus) { }


void OSCReceiver::ProcessMessage( const osc::ReceivedMessage& m, 
                            const IpEndpointName& remoteEndpoint ) {
   
    
    try{
        // example of parsing single messages. osc::OsckPacketListener
        // handles the bundle traversal.
        
        std::cout << "here i m " << std::endl;
        
        if( std::strcmp( m.AddressPattern(), address ) == 0 ){
            // example #1 -- argument stream interface
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 a1;
            osc::int32 id;
            float a3;
            float amp;            
            args >> a1 >> id >> a3 >> amp >> osc::EndMessage;
            
           // this waaaay too specific here in the class
            // make more polymorphic
            Toroid** beads = abacus->getBeads();
            std::cout << "a1 = " << a1 << std::endl;
            // NOTE remove multiplication here
             if (id > -1 && id < abacus->getCols() *  abacus->getRows()){
                 beads[id]->setAmp(amp);
            }
            
        } else {   std::cout << "OSC address not found" << std::endl;   }
    }catch( osc::Exception& e ){
        // any parsing errors such as unexpected argument types, or 
        // missing arguments get thrown as exceptions.
        std::cout << "error while parsing message: "
        << m.AddressPattern() << ": " << e.what() << "\n";
    }
}