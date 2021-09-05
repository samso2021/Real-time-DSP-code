%
% example5_16.m - Comparison of rectangular and Kaiser windows
%                 for spectral analysis
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

fs = 256; N = 128;         % Sampling rate and signal length
f = 61;                    % Frequency of sinewave
n =(0:N-1);                % Time index n
xn = sin(2*pi*f*n/fs);     % Generate 61 Hz sinewave
beta = 8.96;               % Define beta value
wn = (kaiser(N,beta))';    % Kaiser window
x1n = xn.*wn;              % Apply Kaiser window to sinewave
Xk = fft(xn, N);           % FFT of rectangular windowed sinewave
X1k = fft(x1n, N);         % FFT of Kaiser windowed sinewave
normalG = N/sum(abs(wn));  % Normalized the gain against rectangular Win
absXk = abs(Xk);           % Rectangular windowed spectrum
absX1k = normalG*abs(X1k); % Kaiser windowed spectrum
plot(n,absXk,n,absX1k); 
axis([1 64 0 60]);         % Show only up to pi (fs/2)
xlabel('Frequency index, k'); 
ylabel('Magnitude');