%
% example11_5.m - MATLAB script for Example 11.5
%   This routine uses 2-D filter kernals for image filter process
%
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

%
%         'delta'     for a delat filter has no effect to the image
%         'average'   for an averaging filter
%         'sharp'     for a sharp contrast enhancement filter
%         'sobel'     for a Sobel horizontal edge-emphasizing filter 
%         'prewitt'   for a Prewitt vertical edge-emphasizing filter 
%         'laplacian' for a filter approximating 2-D Laplacian operator
%         'emboss'    for a filter approximating 3-D effect
%

clear;
delta_filt = [0  0  0; ...         % Delat filter
              0  1  0; ...
              0  0  0];            

lowpass_filt = [1  1  1; ...       % Low pass (average) filter
                1  1  1; ...
                1  1  1]/9;          

highpass_filt = [-1  -4 -1; ...    % High pass (sharp) filter
                 -4  26 -4; ...
                 -1  -4 -1]/6; 

sobel_filt = [1   2   1; ...       % Sobel filter (horizontal arrangement)
              0   0   0; ...
             -1  -2  -1];

prewitt_filt = [1  0 -1; ...       % Prewitt filter (vertical arragenment)
                1  0 -1; ...
                1  0 -1];          

laplacian_filt = [1   4   1; ...   % Laplacian filter
                  4 -20   4; ...
                  1   4   1];

emboss_filt = [-4 -4   0; ...      % Modified diagnal emboss filter
               -4  1   4; ...
                0  4   4];

blur_filt = [0   1   0; ...        % Blur filter
             1   4   1; ...
             0   1   0]/8;

edge_filt = [-1  -1  -1; ...       % Edge filter (edge in all direction)
             -1   8  -1; ...
             -1  -1  -1];

engrave_filt = [-1   0   0; ...    % Emboss and engrave filter
                 0   2   0; ...
                 0   0   0];

RGB = imread('example11.5.jpg');   % Read the image in

[imHeight, imWidth, color] = size(RGB); % Get the width and height

figure(1), image(RGB);             % Display the original image
title('Origianl JPEG Image');      

for i=2:11
    if i == 2                      % Load filter
        filt = delta_filt;
    elseif i == 3
        filt = lowpass_filt;
    elseif i == 4
        filt = highpass_filt;
    elseif i == 5
        filt = sobel_filt;
    elseif i == 6
        filt = prewitt_filt;
    elseif i == 7
        filt = laplacian_filt;             
    elseif i == 8
        filt = emboss_filt;    
    elseif i == 9
        filt = blur_filt;
    elseif i == 10
        filt = edge_filt;      
    else
        filt = engrave_filt;
    end

if 0 % Use 3 2-D filters
    R = filter2(filt, RGB(:,:,1)); % Filter the image
    G = filter2(filt, RGB(:,:,2));
    B = filter2(filt, RGB(:,:,3));
    newRGB(:,:,1) = uint8(R);
    newRGB(:,:,2) = uint8(G);
    newRGB(:,:,3) = uint8(B);
else % Use image-filter
    newRGB = imfilter(RGB, filt);  % Filter the image
end
     
    figure(i), image(newRGB);      % Display filtered image 

    if i == 2                      % Find which filter was used
        title('Delta Filtered Image');
    elseif i == 3
        title('Lowpass Filtered Image');
    elseif i == 4
        title('Highpass Filtered Image');
    elseif i == 5
        title('Sobel H-Filtered Image');
    elseif i == 6
        title('Prewitt V-Filtered Image');
    elseif i == 7
        title('Laplacian Filtered Image');
    elseif i == 8
        title('Emboss Filtered Image');  
    elseif i == 9
        title('Blur Filtered Image');      
    elseif i == 10
        title('Edge Filtered Image');      
    else        
        title('Engrave Filtered Image');                 
    end

end

