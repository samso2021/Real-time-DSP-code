%
% exmpple2_21.m - Compute and plot spectrum of sinewave corrupted 
%                 by white noise with SNR = 0 dB
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

load -ascii xn.dat;    % Load signal generated by example 2.20
N=length(xn);
n = [0:N-1];           % Time index
Xk=fft(xn,N);
magX=20*log10(abs(Xk));
plot(n,magX)           % Plot the spectrum
xlabel('Frequency index, k'); ylabel('Magnitude (dB)');
axis([0 128 -inf inf])
