%
% example3_2.m - Magnitude and phase response of comb filter
%                with L = 8
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b=[1 0 0 0 0 0 0 0 -1]; a=[1]; % Define parameters
freqz(b, a);                   % Show magnitude and phase response
