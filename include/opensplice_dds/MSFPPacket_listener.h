/**
Software License Agreement (BSD)
\file      MSFPPacket_listener.h
\authors Xuefeng Chang <changxuefengcn@163.com>
\copyright Copyright (c) 2016, the micROS Team, HPCL (National University of Defense Technology), All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of micROS Team, HPCL, nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WAR-
RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, IN-
DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MSFPPACKET_LISTENER_H_
#define MSFPPACKET_LISTENER_H_

#include <string>
#include <sstream>
#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "ccpp_dds_dcps.h" 
#include "opensplice_dds/check_status.h"
#include "ccpp_MSFPPacket.h"

namespace micros_swarm_framework{

    class MSFPPacketListener: public virtual DDS::DataReaderListener
    {
        public:
            MSFPPacketDataReader_var MSFPPacketDR_;
            
            boost::function<void(const MSFPPacket&)> callBack_;

	        MSFPPacketListener () 
	        {
		    
	        }

            //Callback method implementation
            virtual void on_data_available(DDS::DataReader_ptr reader)
              THROW_ORB_EXCEPTIONS;

            virtual void on_requested_deadline_missed(DDS::DataReader_ptr reader,
              const DDS::RequestedDeadlineMissedStatus &status)THROW_ORB_EXCEPTIONS;

            virtual void on_requested_incompatible_qos(DDS::DataReader_ptr reader,
              const DDS::RequestedIncompatibleQosStatus &status)THROW_ORB_EXCEPTIONS;

            virtual void on_sample_rejected(DDS::DataReader_ptr reader, const DDS
              ::SampleRejectedStatus &status)THROW_ORB_EXCEPTIONS;

            virtual void on_liveliness_changed(DDS::DataReader_ptr reader, const DDS
              ::LivelinessChangedStatus &status)THROW_ORB_EXCEPTIONS;

            virtual void on_subscription_matched(DDS::DataReader_ptr reader, const
              DDS::SubscriptionMatchedStatus &status)THROW_ORB_EXCEPTIONS;

            virtual void on_sample_lost(DDS::DataReader_ptr reader, const DDS
              ::SampleLostStatus &status)THROW_ORB_EXCEPTIONS;
    };
};
#endif
