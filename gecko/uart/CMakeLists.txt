include( ./auto.cmake )
leos_obj_link( GeckoUART "cstatic" GeckoUART.cpp )
leos_fs( GeckoUART /drv )
