%
%  example10_2.m - MATLAB script for FFT 50% overlapping
%
%  Description: Hanning windowed 50% block processing
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
clear;
fs = 8000; f = 1000; N = 64;       % Sampling rate,tone,FFT size
n =(0:2*N-1);                      % n=0,..., 127
w = hanning(N)';                   % Hanning window 
xn = sin(2*pi*f*n/fs);             % Generate 1000 Hz sinewave
yn = zeros(size(xn));


% 50% overlap processing
x0 = zeros(size(xn));
x0((1+N/2):N) = xn(1:N/2);          % Very first N/2
Xk = fft(x0(1:N).*w, N);            % N-point FFT
yy(1:N) = ifft(Xk, N);              % N-point iFFT

Xk = fft(xn(1:N).*w, N);            % First N-point FFT
yn(1:N) = ifft(Xk, N);              % First N-point iFFT

y = zeros(size(yn));                % zero out
y(1:N/2) = yy((1+N/2):N)+yn(1:N/2); % Overlap first N/2

Xk = fft(xn((N/2+1):(N/2+N)).*w, N);% (N/2+1):(N/2+N) N-point FFT
yy(1:N) = ifft(Xk, N);              % (N/2+1):(N/2+N) N-point  iFFT
y((N/2+1):N) = yy(1:N/2)+ yn((N/2+1):N); % Overlap second N/2

Xk = fft(xn((N+1):2*N).*w, N);      % Second N-point FFT
yn((N+1):2*N) = ifft(Xk, N);        % Second N-point iFFT
y((N+1):(N/2+N)) = yy((1+N/2):N)+ yn((N+1):(N/2+N)); % Overlap third N/2

Xk = fft(xn((N/2+N+1):(2*N)).*w(1:N/2), N);% N-point FFT
yy(1:N) = ifft(Xk, N);              % N-point iFFT
y((N/2+N+1):(2*N)) = yy(1:N/2)+ yn((N/2+N+1):(2*N)); % Overlap last N/2

figure; plot(n,xn);                 % Original 
axis([1 128 -1.5 1.5]);             % Show only up to pi (fs/2)
title('Original waveform');
xlabel('Sample index, n'); ylabel('Amplitude');

figure; plot(n,y);                  % With 50% overlap
axis([1 128 -1.5 1.5]);             % Show only up to pi (fs/2)
title('Reconstructed waveform using 64-point FFT/IFFT with 50% overlap');
xlabel('Sample index, n'); ylabel('Amplitude');




