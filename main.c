#include <stdio.h>
#include <stdint.h>

#include "mpu6050_userspace.c"

int main()
{
    printf("__ init __ \n");

    struct mpu6050_dev *dev = mpu6050_open("/dev/i2c-2", 0x68);

    mpu6050_reginit(dev);

    //while ( 1 )
    //{

        mpu6050_readdata(dev);

        printf("accel %d %d %d \n", dev->accel_x_adc, dev->accel_y_adc, dev->accel_z_adc);
        printf("gyro %d %d %d \n", dev->gyro_x_adc, dev->gyro_y_adc, dev->gyro_z_adc);

        usleep(1000 * 1000 );
    //}

    mpu6050_release(dev);
}