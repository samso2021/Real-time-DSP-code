%
% example5_19.m - Overlap-add technique for fast covolution
%                 to implement FIR filter that attenuate 
%                 1000 Hz tonal noise in speech file
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

load timit2.asc;           % Speech sampled at 8 kHz, 16 bits
fs = 8000;                 % Sampling rate
disp('Play original speech');
soundsc(timit2, fs, 16);   % Play pure speech

Nx = length(timit2);       % Length of speech file
n = (0:Nx-1); 
f = 1000;                  % Frequency of sinewave
omega = 2*pi*f/fs;
sinewave = 2000*sin(omega*n);
xn = timit2'+sinewave;     % Corrupt speech by 1 kHz tone
disp('Press any key to play noisy speech');
pause;
soundsc(xn, fs, 16);       % Play noisy speech

figure(1);
% Display the spectrogram of noisy speech
spectrogram(xn,kaiser(256,5),200,256,fs,'yaxis')
%specgram(xn, 256, fs)     % Older MATLAB function specgram()
title('Spectrogram of noisy Timit2');

disp('Press any key to play filtered noisy speech');
pause;
Wn = [900  1100]/4000;
b = fir1(128, Wn, 'stop'); % Design an FIR filter
yn = fftfilt(b, xn);       % FIR filtering using overlap-add
soundsc(yn, fs, 16);       % Play filtered speech
figure(2);
% Display the spectrogram of filtered speech
spectrogram(yn,kaiser(256,5),200,256,fs,'yaxis')
%specgram(yn, 256, fs)     % Older MATLAB function specgram()
title('Spectrogram of filtered Timit2');