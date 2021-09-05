%
% example5_10.m - Compute amplitude spectrum of sinewave using
%                 FFT and display it.
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

fs = 256;                  % Sampling rate 
f = 50;                    % Sinewave frequency
N = 128;
n =(0:N-1);                % Time index
xn = sin(2*pi*f*n/fs);     % Generate 50 Hz sinewave
Xk = fft(xn, N);           % FFT computation
absXk = abs(Xk);           % Magnitude spectrum
plot(n, absXk);            % Plot amplitude spectrum
axis([1 64 0 inf]);        % Show only up to pi (fs/2)
xlabel('Frequency index, k'); 
ylabel('Magnitude');