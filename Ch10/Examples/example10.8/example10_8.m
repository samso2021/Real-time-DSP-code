% 
%  example10_8.m - MATLAB script for room reverberate sounds
%
%  Description: create room reverberate sounds
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

clear;
fid1 = fopen('roomImp.pcm','rb');       % Read room impulse response
fid = fopen('out16.dat.pcm','wb');      
fid2 = fopen('audioIn.pcm','rb');
h = fread(fid1,30000,'short');
plot(h(1:30000)),  title('Room impulse response');
xlabel('Time'), ylabel('Amplitude');
fclose(fid1);

% Filtering
x = fread(fid2,'short');
y=conv(h',x)/32768;
fwrite(fid,y,'short');
fclose(fid);
fclose(fid2);

Fs = 8000;
disp('play input audio; when finished press a key to play output audio');
sound(x/32768, Fs);
pause;
disp('play output audio');
sound(y/32768, Fs);