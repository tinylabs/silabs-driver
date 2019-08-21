include( ./auto.cmake )
leos_obj_link( GeckoGPIO "cstatic" GeckoGPIO.cpp )
leos_fs( GeckoGPIO /drv )
