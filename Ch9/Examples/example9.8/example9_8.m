% 
%  Chapter 9 example: angle difference
%  File name:	example9_8.m 
%
%  Description: Using FFT to calculate the angle difference between voice and corrupted voice		 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

clear;
fftL=256;                               % Length of fft used to calculate the spectrum
fs=8000;                                % Sampling frequency 
frame=256;                              % LPC frame size
start=3192;                             % Start point of the input voice
f=fs*(0:(fftL/2-1))/fftL;               % Frequency scale for display

fil=fopen('voice4.pcm','r');            % Open the pcm data file
b= fread(fil,20000,'short');            % Read 72000 samples to b
status=fclose(fil);                     % Close the file

%windowing
w=hamming(frame);                       % Generate hamming window
s=b((start+1):(start+frame));

v = wgn(frame,1,40);                    % Real-valued WGN 
x = v+s;
s = s.*w;                               % Windowing
x = x.*w;

xx=fft(x,fftL);                         % FFT of the specified block
vv=fft(v,fftL);                         % FFT of the specified block
pv=10*log10(vv.*conj(vv)/fftL);         % Magnitude

ss=fft(s,fftL);                         % FFT of the specified block
ps=10*log10(ss.*conj(ss)/fftL);         % Magnitude

angs=angle(ss)*180/pi;                  % Angle
angx=angle(xx)*180/pi;                  % Angle

diffxs = angx - angs;
for i=1:fftL
    if (diffxs(i) >180)diffxs(i) = mod(diffxs(i),-180);
    else if (diffxs(i) <=-180)diffxs(i) = mod(diffxs(i),180);
        end      
    end
end

diffxs((frame/2)+1)=0;
diffxs = diffxs*(pi/180.);

plot(f,ps(1:(fftL/2)),f,pv(1:(fftL/2)),f,diffxs(1:(fftL/2)));
grid;

xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
axis([0 4000 -10 80]);

