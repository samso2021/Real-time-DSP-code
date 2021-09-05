% 
%  example10_7.m - MATLAB script for parametric equalizer
%
%  Description: Bass, Treble, Boost processing
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
clear;
Fs = 16000;       % Sampling frequency
[az1, bz1] = ShelfFilter(1000,-10,1,Fs,'L');
[az2, bz2] = PeakFilter(4000,10,1,Fs);
[az3, bz3] = ShelfFilter(7000,10,1,Fs,'H');

% Combine 3 cascaded IIR filter
da = cascad2x2 (az1,az2); 
db = cascad2x2 (bz1,bz2); 
az = cascad4x2 (da,az3); 
bz = cascad4x2 (db,bz3); 
fvtool(bz,az,bz1,az1,bz2,az2,bz3,az3);
title('Magnitude Response (Bass Trebl Peak Filters with Fs=16000)');

fid1 = fopen('audioIn.pcm','rb');
x = fread(fid1,'short');
fclose(fid1);
y = filter(bz,az,x);    % IIR Filtering

l=length(x);		
out=zeros(l, 2);
out(:,1)=x/32767;		   % Original audio in left channel
out(:,2)=y/32767;		   % Equalized audio in right channel
wavwrite(out, Fs, 'audioOut.wav'); % Write to output

disp('play input audio (left channel) vs. output audio (right channel)');
sound(out, Fs);

% Analysize
figure; spectrum(x); grid;
figure; spectrum(y); grid;
