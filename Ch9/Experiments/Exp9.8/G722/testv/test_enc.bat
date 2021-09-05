..\Release\wamr_enc.exe -dtx 0 tst.inp _tst_m0.cod
..\Release\wamr_enc.exe -dtx 1 tst.inp _tst_m1.cod
..\Release\wamr_enc.exe -dtx 2 tst.inp _tst_m2.cod
..\Release\wamr_enc.exe -dtx 3 tst.inp _tst_m3.cod
..\Release\wamr_enc.exe -dtx 4 tst.inp _tst_m4.cod
..\Release\wamr_enc.exe -dtx 5 tst.inp _tst_m5.cod
..\Release\wamr_enc.exe -dtx 6 tst.inp _tst_m6.cod
..\Release\wamr_enc.exe -dtx 7 tst.inp _tst_m7.cod
..\Release\wamr_enc.exe -dtx 8 tst.inp _tst_m8.cod
..\Release\wamr_enc.exe -dtx 2 dtx.inp _tst_md.cod


fc /b tst_m0.cod _tst_m0.cod
fc /b tst_m1.cod _tst_m1.cod
fc /b tst_m2.cod _tst_m2.cod
fc /b tst_m3.cod _tst_m3.cod
fc /b tst_m4.cod _tst_m4.cod
fc /b tst_m5.cod _tst_m5.cod
fc /b tst_m6.cod _tst_m6.cod
fc /b tst_m7.cod _tst_m7.cod
fc /b tst_m8.cod _tst_m8.cod
fc /b tst_md.cod _tst_md.cod

del _tst_m?.cod

pause

