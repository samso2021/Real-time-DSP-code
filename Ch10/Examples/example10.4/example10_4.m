% 
%  example10_4.m - MATLAB script for graphic equalizer
%
%  Description: 10-band graphic equalizer
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
clear;

% Parameters at sampling rate 48 kHz
bandFreqs = {'31.25','62.5','125','250','500','1k','2k','4k','8k','16k'};
% in dB, must be values
bandGainIndB = [5.0, 8.0, 10.0, 10.0, 12.0, 8.0, 6.0, 4.0, 2.0, 1.0]; 

% Plot the equalizer gain crossing the 10-band
bar(bandGainIndB,0.6);
bandGainLinear = 10.^(bandGainIndB/20.0);  % Linear gain
set(gca,'XTickLabel',bandFreqs);
ylabel('Magnitude (dB)'); xlabel('Frequency (Hz)');
title('10-band Equalizer');
grid on;
axis([0.5 10.5 -1 (max(bandGainIndB)+1)]);

% Read audio file
[x,Fs,bits] = wavread('soxphone48kHz.wav');

% Equalize the signal
[z] = equalizer(bandGainLinear,x);         % Equalization

% Write to output
wavwrite(z, Fs, 'audioOut.wav'); 

% Play sound
disp('play equalized audio');
sound(z, Fs);

