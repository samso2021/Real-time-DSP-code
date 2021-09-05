%
% example5_13.m - Compute and display amplitude spectra of 
%                 two sinewaves
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

fs = 256;               % Sampling rate
N = 128;                % FFT size
f = 50;                 % Frequency of first sinewave 
f1 = 61;                % Frequency of second sinewave
n =(0:N-1);             % Time index n
xn = sin(2*pi*f*n/fs);  % Generate 50 Hz sinewave
x1n = sin(2*pi*f1*n/fs);% Generate 61 Hz sinewave
Xk = fft(xn, N);        % FFT of first sinewave   
X1k = fft(x1n, N);      % FFT of second sinewave
absXk = abs(Xk);        % Magnitude spectrum of first sinewave
absX1k = abs(X1k);      % Magnitude spectrum of second sinewave
plot(n,absXk,n,absX1k); % Show spectra of both sinewave on the
axis([1 64 0 inf]);     % same plot
xlabel('Frequency index, k'); 
ylabel('Magnitude');