%
% example4_3.m - MATLAB script for Example 4.3
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

Fs = 2000;                          % Sampling frequency
Wn = 300;                           % Edge frequency
n = 4;                              % Order of analog filter
[b, a] = butter(n, Wn, 's');        % Design analog filter
[bz, az] = bilinear(b, a, Fs);      % Determine digital filter
freqz(bz,az,512,Fs);                % Display magnitude & phase
