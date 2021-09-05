% 
%  example10_8.m - MATLAB script for Shelf Filter
%
%  Description: calculate Shelf Filter coefficients and display magnitude
%  response
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
%
% function ShelfFilter(Fc, Gain, Q,  Fs, Type)
% Hz--------------------^    ^   ^   ^    ^
% dB-------------------------|   |   |    |
% numerical----------------------|   |    |
% Hz---------------------------------|    |
% Character-------------------------------|

[az1, bz1] = ShelfFilter(2000,10,2,16000,'L');
[az2, bz2] = ShelfFilter(2000, 5,2,16000,'L');
[az3, bz3] = ShelfFilter(2000,-5,2,16000,'L');
[az4, bz4] = ShelfFilter(2000,-10,2,16000,'L');
fvtool(bz1,az1,bz2,az2,bz3,az3,bz4,az4);
title('Low Shelf Filter (Fc=2000, Q=2, Fs=16000)');

clear;
[az1, bz1] = ShelfFilter(6000,10,2,16000,'H');
[az2, bz2] = ShelfFilter(6000,10,1,16000,'H');
[az3, bz3] = ShelfFilter(6000,-10,1,16000,'H');
[az4, bz4] = ShelfFilter(6000,-10,2,16000,'H');
fvtool(bz1,az1,bz2,az2,bz3,az3,bz4,az4);
title('High Shelf Filter (Fc=6000, Q=1 and Q=2, Fs=16000)');


