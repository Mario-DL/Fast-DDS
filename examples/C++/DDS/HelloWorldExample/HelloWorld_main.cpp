// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file HelloWorld_main.cpp
 *
 */

#include "HelloWorldPublisher.h"
#include "HelloWorldSubscriber.h"

int main(
        int argc,
        char** argv)
{
    bool publisher = true;

    // PARSE ARGUMENTS
    if (argc > 1)
    {
        if (strcmp(argv[1], "subscriber") == 0)
        {
            publisher = false;
        }
        else if (strcmp(argv[1], "publisher") != 0)
        {
            std::cout << "publisher OR subscriber argument needed" << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "publisher OR subscriber argument needed" << std::endl;
        return 1;
    }

    // EXECUTE PARTICIPANT PUBLISHER OR SUBSCRIBER
    if (publisher)
    {
        HelloWorldPublisher mypub;
        if(mypub.init())
        {
            mypub.run();
        }
    }
    else
    {
        HelloWorldSubscriber mysub;
        if(mysub.init())
        {
            mysub.run();
        }
    }

    return 0;
}
