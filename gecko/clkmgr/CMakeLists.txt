include( ./auto.cmake )
leos_obj_link( GeckoClkMgr "cstatic" GeckoClkMgr.cpp )
leos_fs( GeckoClkMgr /drv )
