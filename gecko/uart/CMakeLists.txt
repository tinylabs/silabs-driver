include( ./auto.cmake )
get_prop( PARENT )
leos_obj_link( GeckoUART "cstatic ${PARENT}-kstub" GeckoUART.cpp )
leos_fs( GeckoUART /drv )
