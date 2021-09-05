%
% example4_17.m - Design and analysis of two IIR resonators
% Adapted from Help menu
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

Fs = 10000;                % Sampling rate
Wo = 1000/(Fs/2);          % First filter peak frequency
BW = 500/(Fs/2);           % First filter bandwidth
W1 = 2500/(Fs/2);          % Second filter peak frequency
BW1 = 200/(Fs/2);          % Second filter bandwidth
[b,a] = iirpeak(Wo,BW);    % Design first filter
[b1,a1] = iirpeak(W1,BW1); % Design second filter
fvtool(b,a,b1,a1);         % Analyze both filter
