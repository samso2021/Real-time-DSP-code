%
% example5_12a.m - Evaluate quantized 16-bit FFT of sinewave
%                  without scaling 
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

fs = 256;                           % Sampling rate
f = 50;                             % Frequency of sinewave
N = 128;                            % FFT size
n =(0:N-1);                         % Time index n
xn = 0.9999*sin(2*pi*f*n/fs);       % Generate 50 Hz sinewave
FXk = qfft('length',128)            % Create quantized FFT object
qXk = fft(FXk, xn);                 % Compute Q15 FFT
absXk = 128*abs(qXk);               % Magnitude spectrum
plot(n, absXk); axis([1 64 0 inf]); % Show only up to pi (fs/2)
title('Spectrum estimation using quantized FFT');
xlabel('Frequency index, k'); 
ylabel('Magnitude');