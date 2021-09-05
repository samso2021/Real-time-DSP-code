%
% example 7_2 - MATLAB code for generating chirp signal 
%               and show its waveform and spectrogram
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

Fs = 1000;                  % Sampling rate
T = 1/Fs;                   % Sampling period
t = 0:T:1;                  % 1 second @ 1 kHz sample rate
y = chirp(t,100,1,400);     % From 100 Hz to 400 Hz in 1 second
plot(t,y);                  % Plot waveform
xlabel('Time');
ylabel('Amplitude');
figure;
%SPECTROGRAM(X,WINDOW,NOVERLAP,NFFT,Fs)
spectrogram(y,128,120,128,Fs,'yaxis');% Spectrogram
%soundsc(y, Fs)             % Play sound