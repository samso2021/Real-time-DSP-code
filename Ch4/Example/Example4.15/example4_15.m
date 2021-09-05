%
% example4_15.m - Design and implementation of IIR filter
%
% 1. Generate a signal consists of sinewave (150 Hz), corrupted by
%    white noise with SNR = 0 dB, sampling rate is 1,000 Hz
% 2. Design a bandpass IIR filter similar as example5_11.m
% 3. Filtering noisy input and show both input and output
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd


Fs = 1000;                     % Samplng rate
f0 = 150;
N=300; 
A=sqrt(2); 
w0=2*pi*f0/Fs;                 
n = [0:N-1];                   % Time index
sn = A*sin(w0*n);              % Sine sequence
sd = 12357; rng(sd);           % Define seed value
vn = (rand(1,N)-0.5)*sqrt(12); % Zero-mean, unit-variance white noise
xn = sn+vn;                    % Sinewave embedded in white noise

%  Design a bandpass filter
Wp = [140  160]/(Fs/2);        % Passband edge frequencies
Ws = [120  180]/(Fs/2);        % Stopband edge frequencies
Rp = 3;                        % Passband ripple
Rs = 40;                       % Stopband ripple
[N, Wn] = buttord(Wp, Ws, Rp, Rs); % Find the order
[b, a] = butter(N, Wn);        % Design an IIR filter

y = filter(b, a, xn);          % IIR filtering
subplot(2,1,1); 
plot(n, xn);
xlabel('Time index, n'); ylabel('Amplitude');
subplot(2,1,2); 
plot(n, y);
xlabel('Time index, n'); ylabel('Amplitude');
