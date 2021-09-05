%
% example5_18.m - Play and compute spectrogram of speech file
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

load timit2.asc;      % Speech sampled at 8 kHz, 16 bits
soundsc(timit2, 8000) % Play the speech
spectrogram(timit2,256,200,256,8000,'yaxis')
%specgram(timit2, 256, 8000) % Older MATLAB function specgram()