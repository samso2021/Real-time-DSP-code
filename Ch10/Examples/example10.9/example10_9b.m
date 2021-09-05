% 
%  example10_9b.m - MATLAB script for phaser vocoder
%  Audio Time Stretch 
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
N= 256;                       % FFT size

% Ratio to do time stretch
% < 1.0 play audio faster
% > 1.0 play audio slower

r = input('enter tretch ratio r: (0.5 < r < 1.5)\n');

Fs = 8000;                    % Sampling frequency
new = Fs*r;

% open files
fil1=fopen('f301a.pcm','rb'); % Input file
fil2=fopen('outStrech.pcm','wb');  % Output file

x=fread(fil1,'integer*2');    % Linnear PCM format

y = pvoc(x, r, N);       ;    % Phase vocoder 
 
fwrite(fil2,y,'integer*2');   % Write output

status=fclose(fil1);          % Close the file
status=fclose(fil2);

disp('play input audio; when finish press a key to play output audio');
sound(x/32767, Fs);
pause
disp('play output audio');
sound(y/32767, Fs);