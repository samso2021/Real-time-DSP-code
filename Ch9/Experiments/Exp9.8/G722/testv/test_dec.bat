..\Release\wamr_dec.exe tst_m0.cod _tst_m0.out
..\Release\wamr_dec.exe tst_m1.cod _tst_m1.out
..\Release\wamr_dec.exe tst_m2.cod _tst_m2.out
..\Release\wamr_dec.exe tst_m3.cod _tst_m3.out
..\Release\wamr_dec.exe tst_m4.cod _tst_m4.out
..\Release\wamr_dec.exe tst_m5.cod _tst_m5.out
..\Release\wamr_dec.exe tst_m6.cod _tst_m6.out
..\Release\wamr_dec.exe tst_m7.cod _tst_m7.out
..\Release\wamr_dec.exe tst_m8.cod _tst_m8.out
..\Release\wamr_dec.exe tst_md.cod _tst_md.out

fc /b tst_m0.out _tst_m0.out
fc /b tst_m1.out _tst_m1.out
fc /b tst_m2.out _tst_m2.out
fc /b tst_m3.out _tst_m3.out
fc /b tst_m4.out _tst_m4.out
fc /b tst_m5.out _tst_m5.out
fc /b tst_m6.out _tst_m6.out
fc /b tst_m7.out _tst_m7.out
fc /b tst_m8.out _tst_m8.out
fc /b tst_md.out _tst_md.out


del _tst_m?.out

pause