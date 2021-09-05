%
%  example10_10.m - MATLAB script for Tremolo Effect
%
%  Description: Tremolo Effect
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
clear;
Fr = 1;         % Modulation rate
Fs = 8000;      % Sampling rate, Hz
A = 1;          % Depth

% Read the sample waveform
[x,Fs,bits] = wavread('whiteNoiseIn.wav');

% Time index
n = 1:length(x);

z = (1+ A*sin(2*pi*n*(Fr/Fs)))';    % TremoloSweep
y = z.*x;
% Write output
wavwrite(y,Fs,bits,'whiteNoiseOut.wav');
disp('play output audio');
sound(y, Fs);
