% 
%  equalizer.m -  MATLAB cript for Example 10.4, graphic equalizer
%
%  Description: 10-band graphic equalizer
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
function [z]= equalizer (bandGain,x)

Fs = 48000;                        % Sampling frequency
N = 4096;
w = hanning(N)';                   % Hanning window 
[gain] = GainTbl(bandGain);

% 50% overlap processing
z = zeros(size(x));
x0 = zeros(length(N));
x0((1+N/2):N) = x(1:N/2);           % Very first N/2
Xk = fft(x0(1:N).*w, N);            % N-point FFT
yy(1:N) = ifft(Xk, N);              % N-point iFFT
y = zeros(length(2*N));             % zero out

% looping 
for id = 1:(2*N):length(x)-(3*N)
    
xn =x((id):(id-1+3*N))';
Xk = fft(xn(1:N).*w, N);            % First N-point FFT
[Xy]=GainAdjust(Xk,gain');
yn(1:N) = ifft(Xy, N);              % First N-point iFFT
y(1:N/2) = yy((1+N/2):N)+yn(1:N/2); % Overlap first N/2

Xk = fft(xn((N/2+1):(N/2+N)).*w, N);% (N/2+1):(N/2+N) N-point FFT
[Xy]=GainAdjust(Xk,gain');
yy(1:N) = ifft(Xy, N);              % (N/2+1):(N/2+N) N-point  iFFT
y((N/2+1):N) = yy(1:N/2)+ yn((N/2+1):N); % Overlap second N/2

Xk = fft(xn((N+1):2*N).*w, N);     % Second N-point FFT
[Xy]=GainAdjust(Xk,gain');
yn((N+1):2*N) = ifft(Xy, N);       % Second N-point iFFT
y((N+1):(N/2+N)) = yy((1+N/2):N)+ yn((N+1):(N/2+N)); % Overlap third N/2

Xk = fft(xn((N/2+N+1):(N/2 + 2*N)).*w, N);% N-point FFT
[Xy]=GainAdjust(Xk,gain');
yy(1:N) = ifft(Xy, N);              % N-point iFFT
y((N/2+N+1):(2*N)) = yy(1:N/2)+ yn((N/2+N+1):(2*N)); % Overlap last N/2
   
z((id):(id-1+2*N)) = real(y);

end

% Normalization
z = z/max(z);

end

%--------------------------------------------------------------------------
% Apply Gain to echo FFT bin
%--------------------------------------------------------------------------
function [Xo] = GainAdjust(in, gain)
    Xo = zeros(4096,1);
    Xo(1:2048) = in(1:2048).*gain;
    Xo(2049:4096) = in(2049:4096).* gain(2048:-1:1);    
end

%--------------------------------------------------------------------------
% 10-band gain distribution among 2048 FFT bins
%--------------------------------------------------------------------------
function [out] = GainTbl(bandGain)
    out = ones(2048,1);
    out(1:4) = bandGain(1:1);           % 0.00000 - 46.8750 Hz
    out(5:8) = bandGain(2:2);           % 46.8750 - 93.7500 Hz
    out(9:16) = bandGain(3:3);          % 93.7500 - 187.500 Hz
    out(15:32) = bandGain(4:4);         % 187.500 - 375.000 Hz
    out(31:64) = bandGain(5:5);         % 375.000 - 750.000 Hz
    out(65:128) = bandGain(6:6);        % 750.000 - 1500.00 Hz
    out(129:256) = bandGain(7:7);       % 1500.00 - 3000.00 Hz
    out(257:512) = bandGain(8:8);       % 3000.00 - 6000.00 Hz
    out(513:1024) = bandGain(9:9);      % 6000.00 - 12000.0 Hz
    out(1025:2048) = bandGain(10:10);   % 12000.0 - 24000.0 Hz  
end  