%
% example5_17.m - Power spectral density of two sinewaves
%                 embedded in random noise
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

randn('state',0)         % Initialize random signal generator
fs = 1000;               % Sampling frequency
t = (0:fs/10)./fs;       % generate 100 samples
A = [1 2];               % Amplitudes of 2 sinewaves
f = [150;140];           % Frequencies of sinewaves
xn = A*sin(2*pi*f*t) + 0.1*randn(size(t));
Hs=spectrum.periodogram;
psd(Hs,xn,'Fs',fs,'NFFT',1024)