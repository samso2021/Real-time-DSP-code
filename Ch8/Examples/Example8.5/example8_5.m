%
% example8_5.m - MATLAB script for Example 8.5
%   Subband filter coefficients calculation
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%
clear;
NFILT  = 256;  % length of base prototype filter
hNFILT1 = (NFILT+1.0)/2.0;  %(NFILT +1)/2
NBAND = 16;                 % number of filter banks
MARGIN = 0.000000001;       % To void log(0) operation

N=1024;                     % FFT length
hN=N/2;
f=8000*(0:(hN-1))/N;        % Frequency point for plot
SCALE = 1000;

% First half base band filter coefficients 
% Stop band at pi/16 with -110 db attenuation
baseB =[
    0.0041,    0.0023,    0.0028,    0.0032,    0.0035,    0.0037,    0.0036,    0.0031, ...
    0.0022,    0.0007,   -0.0015,   -0.0046,   -0.0086,   -0.0137,   -0.0201,   -0.0278, ...
   -0.0370,   -0.0478,   -0.0602,   -0.0742,   -0.0899,   -0.1071,   -0.1258,   -0.1457, ...
   -0.1667,   -0.1882,   -0.2101,   -0.2317,   -0.2525,   -0.2718,   -0.2889,   -0.3030, ...
   -0.3133,   -0.3189,   -0.3187,   -0.3119,   -0.2974,   -0.2744,   -0.2418,   -0.1990, ...
   -0.1452,   -0.0798,   -0.0023,    0.0874,    0.1894,    0.3034,    0.4289,    0.5651, ...
    0.7107,    0.8645,    1.0244,    1.1884,    1.3538,    1.5178,    1.6772,    1.8284, ...
    1.9678,    2.0912,    2.1946,    2.2737,    2.3242,    2.3418,    2.3223,    2.2619, ...
    2.1568,    2.0038,    1.8002,    1.5439,    1.2333,    0.8678,    0.4476,   -0.0262, ...
   -0.5514,   -1.1247,   -1.7419,   -2.3972,   -3.0842,   -3.7948,   -4.5201,   -5.2499, ...
   -5.9732,   -6.6777,   -7.3506,   -7.9782,   -8.5461,   -9.0397,   -9.4442,   -9.7443, ...
   -9.9254,   -9.9730,   -9.8731,   -9.6127,   -9.1797,   -8.5633,   -7.7541,   -6.7445, ...
   -5.5285,   -4.1024,   -2.4645,   -0.6153,    1.4420,    3.7022,    6.1571,    8.7964, ...
   11.6071,   14.5740,   17.6794,   20.9036,   24.2247,   27.6192,   31.0619,   34.5264, ...
   37.9851,   41.4098,   44.7717,   48.0422,   51.1926,   54.1949,   57.0221,   59.6484, ...
   62.0495,   64.2029,   66.0884,   67.6881,   68.9868,   69.9719,   70.6339,   70.9666];
   
% Base band filter
base = [baseB baseB((NFILT/2):-1:1)]/SCALE;

freqz(base,1,512,'whole');
y1=fft(base,N);                        % Calculate base band filter magnitude response
pyy1=10*log10(y1.*conj(y1) + MARGIN);
figure; plot(f,pyy1(1:hN));
title('Base band filter frequency response');
xlabel('Frequency (Hz)'); ylabel('Gain (dB)');

s =1:NFILT;
figure; plot(s,base);
title('Base band filter impuls response');
xlabel('Time index, n'); ylabel('Amplitude');
axis([0 NFILT -0.01 0.08]);

% Allocate array for the subband filter coefficients
t16=ones(NFILT,NBAND);                  % Analysis real
g16=ones(NFILT,NBAND);                  % Sysnthesi real

for (m = 1:1:NBAND)         % 
  hr = (cos((m-0.5)*(pi/NBAND)*((1:NFILT)-hNFILT1)))';  % Calculate shifting for real channels
  hi = (sin((m-0.5)*(pi/NBAND)*((1:NFILT)-hNFILT1)))';  % Calculate shifting for image channels
  
  for (i =1:NFILT)
    t16(i,m) = base(i)*(hr(i) + j*hi(i)); % Analysis filter
    g16(NFILT-i+1,m) = conj(t16(i,m));  % Synthesis filter - Time reversed copy of the analysis filters  
  end 
   
  y1 = fft(t16(1:NFILT,m),N);           % mth analysis subband filter real part response
  y2 = fft(g16(1:NFILT,m),N);           % mth synthesis subband filter real part response
 
  pyy1(1:N,m)=10*log10(y1.*conj(y1) + MARGIN);   % mth analysis subband magnitude response
  pyy2(1:N,m)=10*log10(y2.*conj(y2) + MARGIN);   % mth synthesis subband magnitude response  
  
end

%Analysis filter subband response
figure;
plot(f,pyy1(1:hN,1),f,pyy1(1:hN,2),f,pyy1(1:hN,3),f,pyy1(1:hN,4),f,pyy1(1:hN,5),f,pyy1(1:hN,6),f,pyy1(1:hN,7),f,pyy1(1:hN,8),f,pyy1(1:hN,9),f,pyy1(1:hN,10),f,pyy1(1:hN,11),f,pyy1(1:hN,12),f,pyy1(1:hN,13),f,pyy1(1:hN,14),f,pyy1(1:hN,15),f,pyy1(1:hN,16));
title('16 band analysis filter response');
xlabel('Frequency (Hz)'); ylabel('Gain (dB)');

%Synthesis filter subbnad response
figure;
plot(f,pyy2(1:hN,1),f,pyy2(1:hN,2),f,pyy2(1:hN,3),f,pyy2(1:hN,4),f,pyy2(1:hN,5),f,pyy2(1:hN,6),f,pyy2(1:hN,7),f,pyy2(1:hN,8),f,pyy2(1:hN,9),f,pyy2(1:hN,10),f,pyy2(1:hN,11),f,pyy2(1:hN,12),f,pyy2(1:hN,13),f,pyy2(1:hN,14),f,pyy2(1:hN,15),f,pyy2(1:hN,16));
title('16 band synthesis filter response');
xlabel('Frequency (Hz)'); ylabel('Gain (dB)');

% Analysis filter distortion 
H = fft(t16,N);                         % Perform FFT of analysis filter
Hz = sum(abs(H').^2);                   % Magnitude of the full band
Hzlg = 10*log10(Hz);
figure; plot(f,Hzlg(1:hN));
title('Combined distortion response');
xlabel('Frequency (Hz)'); ylabel('Gain (dB)');




