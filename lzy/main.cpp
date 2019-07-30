//
//  Created by doctor_lin on 7/29/19.
//  Copyright © 2019 doctor_lin. All rights reserved.
//

#include <iostream>
#include "monocular_depth_src.h"

using namespace std;
int main (int argc, char** argv )
{
    if ( argc != 2 )
    {
        cout<<"Usage: dense_mapping path_to_test_dataset"<<endl;
        return -1;
    }
    const int total_frames = 200;
    for (int i; i < total_frames; i++ ){
        getDepthEstimation(argv[1], i, total_frames);
    }
}
