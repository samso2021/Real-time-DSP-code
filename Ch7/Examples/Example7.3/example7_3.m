%
% example7_3.m - MATLAB code to generate wail siren and plays it
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

Fs = 8000;                   % 8 kHz sample rate
T = 1/Fs;                    % Sampling period     
tw = 0:T:4.92;               % 4.92 secs
yw = chirp(tw,800,4.92,1700);% From 800 Hz to 1700 Hz in 4.92 secs
soundsc(yw, Fs)              % Play it
