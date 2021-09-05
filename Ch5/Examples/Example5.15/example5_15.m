%
% example5_15.m - Overlap of two spectral lines due to frequency
%                 separation is less than frequency resolution
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

fs = 256;                  % Sampling rate
N = 128;                   % FFT size
f1 = 60;                   % Frequency of first sinewave
f2 = 61;                   % Frequency of second sinewave
n =(0:N-1);                % Time index n
x1n = sin(2*pi*f1*n/fs);   % Generate 60 Hz sinewave
x2n = sin(2*pi*f2*n/fs);   % Generate 61 Hz sinewave
xn = x1n+x2n;              % Mix these two sinewaves
Xk = fft(xn, N);           % DFT computation
absXk = abs(Xk);           % Magnitude response
plot(n,absXk); 
axis([1 64 0 inf]);        % Show only up to pi (fs/2)
xlabel('Frequency index, k'); 
ylabel('Magnitude');