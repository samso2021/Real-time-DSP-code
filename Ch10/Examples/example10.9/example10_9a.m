%  example10_9a.m - MATLAB script for phaser vocoder
%  Audio Pitch Change
%
%  Description: phase vocoder
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
clear;
N=256;                        % FFT size

% Ratio to scale the pitch
% < 1.0 scale pitch up (to female)
% > 1.0 scale down pitch (to male)
r = input('enter scale ratio r: (0.5 < r < 1.5)\n');

Fs = 8000;                    % Sampling frequency
new = Fs*r;

% open files
fil1=fopen('f301a.pcm','rb'); % Input file
fil2=fopen('outPitch.pcm','wb');   % Output file

x=fread(fil1,'integer*2');    % Linnear PCM format

y = pvoc(x, r, N);       ;    % Phase vocoder 
z = resample(y,new,Fs)   ;    % Reamplling  8000*3/4
   
fwrite(fil2,z,'integer*2');   % Write output

status=fclose(fil1);          % Close the file
status=fclose(fil2);

disp('play input audio; when finish press a key to play output audio');
sound(x/32767, Fs);
pause
disp('play output audio');
sound(z/32767, Fs);