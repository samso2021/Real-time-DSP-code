%
% exercise8_2.m - load and disply audio data
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%
%

clear;
load TIMIT1.ASC;

plot(TIMIT1);
xlabel('Time index, n'), ylabel('Amplitude');

