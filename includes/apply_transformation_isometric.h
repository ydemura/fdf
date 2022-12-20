//
//  apply_transformation_isometric.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef apply_transformation_isometric_h
#define apply_transformation_isometric_h

# include "transform_lines.h"
# include "transformations.h"

void	apply_tranformation_to_whole_line(t_affine_transform matrix,
			int num_of_lines, t_line *lines, t_line *iso_lines);
t_line	*apply_transformation_isometric(t_line *lines, int num_lines,
			t_adjustments *add);

#endif /* apply_transformation_isometric_h */
