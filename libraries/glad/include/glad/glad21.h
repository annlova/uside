#ifndef __uside_glad21_h_
#define __uside_glad21_h_
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
GLAPI int GLAD_GL_VERSION_1_1;
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawArrays'>OpenGL 4</a><br /><a  href='../gl3/glDrawArrays'>OpenGL 3</a><br /><a  href='../gl2/glDrawArrays'>OpenGL 2</a><br /><a  href='../es3/glDrawArrays'>OpenGL ES 3</a><br /><a  href='../es2/glDrawArrays'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glDrawArrays</h1>
    <div class="refentry" id="glDrawArrays">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawArrays — render primitives from array data</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawArrays</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">first</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">count</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies what kind of primitives to render.
                    Symbolic constants
                    <code class="constant">GL_POINTS</code>,
                    <code class="constant">GL_LINE_STRIP</code>,
                    <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>,
                    <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_LINES_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLE_STRIP</code>,
                    <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>,
                    <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code> and <code class="constant">GL_PATCHES</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>first</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the starting index in the enabled arrays.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>count</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of indices to be rendered.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawArrays</code> specifies multiple geometric primitives
            with very few subroutine calls. Instead of calling a GL procedure
            to pass each individual vertex, normal, texture coordinate, edge
            flag, or color, you can prespecify
            separate arrays of vertices, normals, and colors and use them to
            construct a sequence of primitives with a single
            call to <code class="function">glDrawArrays</code>.
        </p>
        <p>
            When <code class="function">glDrawArrays</code> is called, it uses <em class="parameter"><code>count</code></em> sequential elements from each
            enabled array to construct a sequence of geometric primitives,
            beginning with element <em class="parameter"><code>first</code></em>. <em class="parameter"><code>mode</code></em> specifies what kind of
            primitives are constructed and how the array elements
            construct those primitives.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glDrawArrays</code> have an
            unspecified value after <code class="function">glDrawArrays</code> returns. Attributes that aren't
            modified remain well defined.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
            <code class="constant">GL_LINES_ADJACENCY</code>,
            <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and
            <code class="constant">GL_TRIANGLES_ADJACENCY</code>
            are available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
      </div>
      <div class='refsect1' id='examples'><h2>Examples</h2><div class='example'>Render a vertex array (not loaded into OpenGL) using texture UV, color, and normal vertex attributes.<pre class='programlisting'><a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(texcoord_attrib_index); <span class='codecomment'>// Attribute indexes were received from calls to <a href='../gl4/glGetAttribLocation'>glGetAttribLocation</a>, or passed into <a href='../gl4/glBindAttribLocation'>glBindAttribLocation</a>.</span>
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(normal_attrib_index);
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(color_attrib_index);
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(position_attrib_index);

<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(texcoord_attrib_index, 2, <span class='constant'>GL_FLOAT</span>, false, 0, texcoords_data); <span class='codecomment'>// texcoords_data is a <span class='ckeyword'>float</span>*, 2 per vertex, representing UV coordinates.</span>
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(normal_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, 0, normals_data); <span class='codecomment'>// normals_data is a <span class='ckeyword'>float</span>*, 3 per vertex, representing normal vectors.</span>
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(color_attrib_index, 3, <span class='constant'>GL_UNSIGNED_BYTE</span>, true, <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>unsigned</span> <span class='ckeyword'>char</span>)*3, colors_data); <span class='codecomment'>// colors_data is a <span class='ckeyword'>unsigned</span> <span class='ckeyword'>char</span>*, 3 per vertex, representing the color of each vertex.</span>
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(position_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, 0, vertex_data); <span class='codecomment'>// vertex_data is a <span class='ckeyword'>float</span>*, 3 per vertex, representing the position of each vertex</span>

<a href='../gl4/glDrawArrays'>glDrawArrays</a>(<span class='constant'>GL_TRIANGLES</span>, 0, vertex_count); <span class='codecomment'>// vertex_count is an integer containing the number of indices to be rendered</span>

<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(position_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(texcoord_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(normal_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(color_attrib_index);
</pre></div></div><div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://antongerdelan.net/opengl/hellotriangle.html">Anton Gerdelan - "Hello Triangle" - OpenGL 4 Up and Running</a><br /><a href="https://antongerdelan.net/opengl/cubemaps.html">Anton Gerdelan - Cube Maps: Sky Boxes and Environment Mapping</a><br /><a href="https://antongerdelan.net/opengl/vertexbuffers.html">Anton Gerdelan - Vertex Buffer Objects</a><br /><a href="https://open.gl/depthstencils">open.gl - Depth and Stencil Buffers</a><br /><a href="https://open.gl/geometry">open.gl - Geometry Shaders</a><br /><a href="https://open.gl/drawing">open.gl - The Graphics Pipeline</a><br /><a href="https://open.gl/feedback">open.gl - Transform Feedback</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/">opengl-tutorial.org - Tutorial 2 : The first triangle</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/">opengl-tutorial.org - Tutorial 4 : A Colored Cube</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glDrawArrays</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDrawArraysInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawArraysInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElements"><span class="citerefentry"><span class="refentrytitle">glDrawElements</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>,
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawArrays.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glDrawArrays glad_glDrawArrays
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI PFNGLDRAWELEMENTSPROC glad_glDrawElements;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDrawElements'>OpenGL 4</a><br /><a  href='../gl3/glDrawElements'>OpenGL 3</a><br /><a  href='../gl2/glDrawElements'>OpenGL 2</a><br /><a  href='../es3/glDrawElements'>OpenGL ES 3</a><br /><a  href='../es2/glDrawElements'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glDrawElements</h1>
    <div class="refentry" id="glDrawElements">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDrawElements — render primitives from array data</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDrawElements</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">mode</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">count</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">indices</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>mode</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies what kind of primitives to render.
                    Symbolic constants
                    <code class="constant">GL_POINTS</code>,
                    <code class="constant">GL_LINE_STRIP</code>,
                    <code class="constant">GL_LINE_LOOP</code>,
                    <code class="constant">GL_LINES</code>,
                    <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_LINES_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLE_STRIP</code>,
                    <code class="constant">GL_TRIANGLE_FAN</code>,
                    <code class="constant">GL_TRIANGLES</code>,
                    <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code>,
                    <code class="constant">GL_TRIANGLES_ADJACENCY</code> and <code class="constant">GL_PATCHES</code>
                    are accepted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>count</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of elements to be rendered.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>type</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the type of the values in <em class="parameter"><code>indices</code></em>. Must be one of
                    <code class="constant">GL_UNSIGNED_BYTE</code>, <code class="constant">GL_UNSIGNED_SHORT</code>, or
                    <code class="constant">GL_UNSIGNED_INT</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>indices</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies an offset of the first index in the array in the data store of the buffer currently bound to 
                    the GL_ELEMENT_ARRAY_BUFFER target. 
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDrawElements</code> specifies multiple geometric primitives
            with very few subroutine calls. Instead of calling a GL function
            to pass each individual vertex, normal, texture coordinate, edge
            flag, or color, you can prespecify
            separate arrays of vertices, normals, and so on, and use them to
            construct a sequence of primitives with a single
            call to <code class="function">glDrawElements</code>.
        </p>
        <p>
            When <code class="function">glDrawElements</code> is called, it uses <em class="parameter"><code>count</code></em> sequential elements from an
            enabled array, starting at <em class="parameter"><code>indices</code></em> to construct a sequence of
            geometric primitives. <em class="parameter"><code>mode</code></em> specifies what kind of primitives are
            constructed and how the array elements construct these primitives. If
            more than one array is enabled, each is used.
        </p>
        <p>
            Vertex attributes that are modified by <code class="function">glDrawElements</code> have an
            unspecified value after <code class="function">glDrawElements</code> returns.  Attributes that aren't
            modified maintain their previous values.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="constant">GL_LINE_STRIP_ADJACENCY</code>,
            <code class="constant">GL_LINES_ADJACENCY</code>,
            <code class="constant">GL_TRIANGLE_STRIP_ADJACENCY</code> and
            <code class="constant">GL_TRIANGLES_ADJACENCY</code>
            are available only if the GL version is 3.2 or greater.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>mode</code></em> is not an accepted value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>count</code></em> is negative.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a geometry shader is active and <em class="parameter"><code>mode</code></em>
            is incompatible with the input primitive type of the geometry shader in the currently installed program object.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to an
            enabled array or the element array and the buffer object's data store is currently mapped.
        </p>
      </div>
      <div class='refsect1' id='examples'><h2>Examples</h2><div class='example'>Render an indexed vertex array (not loaded into OpenGL) using texture UV and normal vertex attributes.<pre class='programlisting'><a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(texcoord_attrib_index); <span class='codecomment'>// Attribute indexes were received from calls to <a href='../gl4/glGetAttribLocation'>glGetAttribLocation</a>, or passed into <a href='../gl4/glBindAttribLocation'>glBindAttribLocation</a>.</span>
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(normal_attrib_index);
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(position_attrib_index);

<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(texcoord_attrib_index, 2, <span class='constant'>GL_FLOAT</span>, false, 0, texcoords_data); <span class='codecomment'>// texcoords_data is a <span class='ckeyword'>float</span>*, 2 per vertex, representing UV coordinates.</span>
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(normal_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, 0, normals_data); <span class='codecomment'>// normals_data is a <span class='ckeyword'>float</span>*, 3 per vertex, representing normal vectors.</span>
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(position_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, 0, vertex_data); <span class='codecomment'>// vertex_data is a <span class='ckeyword'>float</span>*, 3 per vertex, representing the position of each vertex</span>

<span class='codecomment'>// num_vertices is the number of verts in your vertex_data.</span>
<span class='codecomment'>// index_data is an array of <span class='ckeyword'>unsigned</span> <span class='ckeyword'>int</span> offsets into vertex_data.</span>
<a href='../gl4/glDrawElements'>glDrawElements</a>(<span class='constant'>GL_TRIANGLES</span>, num_vertices, <span class='constant'>GL_UNSIGNED_INT</span>, index_data);

<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(position_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(texcoord_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(normal_attrib_index);
</pre></div><div class='example'>Render an indexed buffer object using texture UV and normal vertex attributes.<pre class='programlisting'><a href='../gl4/glBindBuffer'>glBindBuffer</a>(<span class='constant'>GL_ARRAY_BUFFER</span>, vertex_buffer); <span class='codecomment'>// vertex_buffer is retrieved from <a href='../gl4/glGenBuffers'>glGenBuffers</a></span>
<a href='../gl4/glBindBuffer'>glBindBuffer</a>(<span class='constant'>GL_ELEMENT_ARRAY_BUFFER</span>, index_buffer); <span class='codecomment'>// index_buffer is retrieved from <a href='../gl4/glGenBuffers'>glGenBuffers</a></span>

<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(texcoord_attrib_index); <span class='codecomment'>// Attribute indexes were received from calls to <a href='../gl4/glGetAttribLocation'>glGetAttribLocation</a>, or passed into <a href='../gl4/glBindAttribLocation'>glBindAttribLocation</a>.</span>
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(normal_attrib_index);
<a href='../gl4/glEnableVertexAttribArray'>glEnableVertexAttribArray</a>(position_attrib_index);

<span class='codecomment'>// vertex_stride is the size of bytes of each vertex in the buffer object</span>
<span class='codecomment'>// vertex_position_offset and kin are the offset in bytes of the position data</span>
<span class='codecomment'>// in each vertex. For example <span class='ckeyword'>if</span> your vertex structure is</span>
<span class='codecomment'>// [ position, texcoord, normal ] then position vertex_position_offset will</span>
<span class='codecomment'>// have offset 0, vertex_texcoord_offset is 12 (position is 3 * <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>float</span>)</span>
<span class='codecomment'>// bytes large, and texcoord comes just after) and vertex_normal_offset is</span>
<span class='codecomment'>// 20 = 5 * <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>float</span>).</span>
GLintptr vertex_texcoord_offset = 3 * <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>float</span>);
GLintptr vertex_normal_offset = 5 * <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>float</span>);
GLintptr vertex_position_offset = 0 * <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>float</span>);

<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(texcoord_attrib_index, 2, <span class='constant'>GL_FLOAT</span>, false, vertex_stride, (GLvoid*)vertex_texcoord_offset);
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(normal_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, vertex_stride, (GLvoid*)vertex_normal_offset);
<a href='../gl4/glVertexAttribPointer'>glVertexAttribPointer</a>(position_attrib_index, 3, <span class='constant'>GL_FLOAT</span>, false, vertex_stride, (GLvoid*)vertex_position_offset);

<span class='codecomment'>// num_vertices is the number of verts in your vertex_data.</span>
<span class='codecomment'>// index_data is an array of <span class='ckeyword'>unsigned</span> <span class='ckeyword'>int</span> offsets into vertex_data.</span>
<a href='../gl4/glDrawElements'>glDrawElements</a>(<span class='constant'>GL_TRIANGLES</span>, num_vertices, <span class='constant'>GL_UNSIGNED_INT</span>, <span class='ckeyword'>NULL</span>);

<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(position_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(texcoord_attrib_index);
<a href='../gl4/glDisableVertexAttribArray'>glDisableVertexAttribArray</a>(normal_attrib_index);
</pre></div></div><div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://web.archive.org/web/20150225192608/http://www.arcsynthesis.org/gltut/Positioning/Tutorial%2005.html">Learning Modern 3D Graphics Programming - Chapter 5. Objects in Depth [Vertex Array Objects, Indexed Drawing]</a><br /><a href="https://open.gl/drawing">open.gl - The Graphics Pipeline</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/">opengl-tutorial.org - Tutorial 13 : Normal Mapping</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glDrawElements</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDrawArrays"><span class="citerefentry"><span class="refentrytitle">glDrawArrays</span></span></a>,
            <a class="citerefentry" href="glDrawElementsInstanced"><span class="citerefentry"><span class="refentrytitle">glDrawElementsInstanced</span></span></a>,
            <a class="citerefentry" href="glDrawElementsBaseVertex"><span class="citerefentry"><span class="refentrytitle">glDrawElementsBaseVertex</span></span></a>,
            <a class="citerefentry" href="glDrawRangeElements"><span class="citerefentry"><span class="refentrytitle">glDrawRangeElements</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDrawElements.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glDrawElements glad_glDrawElements
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
GLAPI PFNGLGETPOINTERVPROC glad_glGetPointerv;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGetPointerv'>OpenGL 4</a><br /><a  href='../gl3/glGetPointerv'>OpenGL 3</a><br /><a  href='../gl2/glGetPointerv'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glGetPointerv</h1>
    <div class="refentry" id="glGetPointerv">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGetPointerv — return the address of the specified pointer</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGetPointerv</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">pname</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLvoid ** <var class="pdparam">params</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pname</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the pointer to be returned. Must be one of
                    <code class="constant">GL_DEBUG_CALLBACK_FUNCTION</code> or
                    <code class="constant">GL_DEBUG_CALLBACK_USER_PARAM</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>params</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Returns the pointer value specified by <em class="parameter"><code>pname</code></em>.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGetPointerv</code> returns pointer information.
            <em class="parameter"><code>pname</code></em> indicates the pointer to be
            returned, and <em class="parameter"><code>params</code></em> is a pointer to a
            location in which to place the returned data. The parameters
            that may be queried include:
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_CALLBACK_FUNCTION</code>
              </span>
            </dt>
            <dd>
              <p>
                        Returns the current callback function set with the
                        <em class="parameter"><code>callback</code></em> argument of
                        <a class="citerefentry" href="glDebugMessageCallback"><span class="citerefentry"><span class="refentrytitle">glDebugMessageCallback</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_CALLBACK_USER_PARAM</code>
              </span>
            </dt>
            <dd>
              <p>
                        Returns the user parameter to the current callback
                        function set with the
                        <em class="parameter"><code>userParam</code></em> argument of
                        <a class="citerefentry" href="glDebugMessageCallback"><span class="citerefentry"><span class="refentrytitle">glDebugMessageCallback</span></span></a>.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="function">glGetPointerv</code> is available in the OpenGL
            core profile only if the GL version is 4.3 or later. It is
            available in the compatibility profile for all GL versions, and
            accepts additional queries. However, these reference pages
            document only the core profile.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>pname</code></em> is not an accepted value.
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glGetPointerv</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDebugMessageCallback"><span class="citerefentry"><span class="refentrytitle">glDebugMessageCallback</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 2014 Khronos Group.
            This material may be distributed subject to the terms and conditions set forth in
            the Open Publication License, v 1.0, 8 June 1999.
            <a class="link" href="https://opencontent.org/openpub/" target="_top">https://opencontent.org/openpub/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGetPointerv.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glGetPointerv glad_glGetPointerv
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
GLAPI PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glPolygonOffset'>OpenGL 4</a><br /><a  href='../gl3/glPolygonOffset'>OpenGL 3</a><br /><a  href='../gl2/glPolygonOffset'>OpenGL 2</a><br /><a  href='../es3/glPolygonOffset'>OpenGL ES 3</a><br /><a  href='../es2/glPolygonOffset'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glPolygonOffset</h1>
    <div class="refentry" id="glPolygonOffset">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glPolygonOffset — set the scale and units used to calculate depth values</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glPolygonOffset</strong>(</code>
              </td>
              <td>GLfloat <var class="pdparam">factor</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLfloat <var class="pdparam">units</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>factor</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a scale factor that is used to create a variable
                    depth offset for each polygon. The initial value is 0.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>units</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Is multiplied by an implementation-specific value to
                    create a constant depth offset. The initial value is 0.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            When <code class="constant">GL_POLYGON_OFFSET_FILL</code>, <code class="constant">GL_POLYGON_OFFSET_LINE</code>, or
            <code class="constant">GL_POLYGON_OFFSET_POINT</code> is enabled, each
            fragment's <span class="emphasis"><em>depth</em></span> value will be offset after it is interpolated
            from the <span class="emphasis"><em>depth</em></span> values of the appropriate vertices.
            The value of the offset is
            <math overflow="scroll">

                <mrow>
                    <mrow>
                        <mi mathvariant="italic">factor</mi>
                        <mo>×</mo>
                        <mi mathvariant="italic">DZ</mi>
                    </mrow>
                    <mo>+</mo>
                    <mrow>
                        <mi mathvariant="italic">r</mi>
                        <mo>×</mo>
                        <mi mathvariant="italic">units</mi>
                    </mrow>
                </mrow>
            </math>,
            where
            <math overflow="scroll">

                <mi mathvariant="italic">DZ</mi>
            </math>
            is a measurement of the change in depth relative to the screen
            area of the polygon, and
            <math overflow="scroll"><mi mathvariant="italic">r</mi></math>
            is the smallest value that is guaranteed to
            produce a resolvable offset for a given implementation.
            The offset is added before the depth test is performed and before
            the value is written into the depth buffer.
        </p>
        <p>
            <code class="function">glPolygonOffset</code> is useful for rendering hidden-line images, for applying decals
            to surfaces, and for rendering solids with highlighted edges.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a> with argument
            <code class="constant">GL_POLYGON_OFFSET_FILL</code>,
            <code class="constant">GL_POLYGON_OFFSET_LINE</code>,
            or <code class="constant">GL_POLYGON_OFFSET_POINT</code>.
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_POLYGON_OFFSET_FACTOR</code> or
            <code class="constant">GL_POLYGON_OFFSET_UNITS</code>.
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glPolygonOffset</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a>,
            <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glPolygonOffset.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glPolygonOffset glad_glPolygonOffset
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyTexImage1D'>OpenGL 4</a><br /><a  href='../gl3/glCopyTexImage1D'>OpenGL 3</a><br /><a  href='../gl2/glCopyTexImage1D'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glCopyTexImage1D</h1>
    <div class="refentry" id="glCopyTexImage1D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyTexImage1D — copy pixels into a 1D texture image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTexImage1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be <code class="constant">GL_TEXTURE_1D</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalformat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the internal format of the texture.
                    Must be one of the following symbolic constants:
                    <code class="constant">GL_COMPRESSED_RED</code>,
                    <code class="constant">GL_COMPRESSED_RG</code>,
                    <code class="constant">GL_COMPRESSED_RGB</code>,
                    <code class="constant">GL_COMPRESSED_RGBA</code>.
                    <code class="constant">GL_COMPRESSED_SRGB</code>,
                    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.
                    <code class="constant">GL_DEPTH_COMPONENT</code>,
                    <code class="constant">GL_DEPTH_COMPONENT16</code>,
                    <code class="constant">GL_DEPTH_COMPONENT24</code>,
                    <code class="constant">GL_DEPTH_COMPONENT32</code>,
                    <code class="constant">GL_STENCIL_INDEX8</code>,
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_R3_G3_B2</code>,
                    <code class="constant">GL_RGB4</code>,
                    <code class="constant">GL_RGB5</code>,
                    <code class="constant">GL_RGB8</code>,
                    <code class="constant">GL_RGB10</code>,
                    <code class="constant">GL_RGB12</code>,
                    <code class="constant">GL_RGB16</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_RGBA2</code>,
                    <code class="constant">GL_RGBA4</code>,
                    <code class="constant">GL_RGB5_A1</code>,
                    <code class="constant">GL_RGBA8</code>,
                    <code class="constant">GL_RGB10_A2</code>,
                    <code class="constant">GL_RGBA12</code>,
                    <code class="constant">GL_RGBA16</code>,
                    <code class="constant">GL_SRGB</code>,
                    <code class="constant">GL_SRGB8</code>,
                    <code class="constant">GL_SRGB_ALPHA</code>, or
                    <code class="constant">GL_SRGB8_ALPHA8</code>.
                </p>
            </dd>
            <dt>
              <span class="term"><em class="parameter"><code>x</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>y</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specify the window coordinates of the left corner
                    of the row of pixels to be copied.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                    The height of the texture image is 1.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Must be 0.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glCopyTexImage1D</code> defines a one-dimensional texture image with pixels from the current
            <code class="constant">GL_READ_BUFFER</code>.
        </p>
        <p>
            The screen-aligned pixel row with left corner at
            <math overflow="scroll">

                <mfenced open="(" close=")">
                    <mi mathvariant="italic">x</mi>
                    <mi mathvariant="italic">y</mi>
                </mfenced>
            </math>
            and with a length of
            <math overflow="scroll">
                <mi mathvariant="italic">width</mi>
            </math>
            defines the texture array
            at the mipmap level specified by <em class="parameter"><code>level</code></em>.
            <em class="parameter"><code>internalformat</code></em> specifies the internal format of the texture array.
        </p>
        <p>
            The pixels in the row are processed exactly as if
            <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a> had been called, but the process stops just before
            final conversion.
            At this point all pixel component values are clamped to the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>
            and then converted to the texture's internal format for storage in the texel
            array.
        </p>
        <p>
            Pixel ordering is such that lower
            <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
            screen coordinates correspond to
            lower texture coordinates.
        </p>
        <p>
            If any of the pixels within the specified row of the current
            <code class="constant">GL_READ_BUFFER</code> are outside the window associated with the current
            rendering context, then the values obtained for those pixels are undefined.
        </p>
        <p>
            <code class="function">glCopyTexImage1D</code> defines a one-dimensional texture image with pixels from the current
            <code class="constant">GL_READ_BUFFER</code>.
        </p>
        <p>
            When <em class="parameter"><code>internalformat</code></em> is one of the sRGB  types, the GL does not automatically convert the source pixels to the sRGB color space.  In this case, the <code class="function">glPixelMap</code> function can be used to accomplish the conversion.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            1, 2, 3, and 4 are not accepted values for <em class="parameter"><code>internalformat</code></em>.
        </p>
        <p>
            An image with 0 width indicates a NULL texture.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX8</code> is accepted for <em class="parameter"><code>internalformat</code></em> only
            if the GL version is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>target</code></em> is not one of the allowable values.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater
            than
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">log</mi>
                    <mn>2</mn>
                    </msub>
                    <mo>⁢</mo>
                    <mi mathvariant="italic">max</mi>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">max</mi></math>
            is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>internalformat</code></em> is not an allowable value.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em> is less than 0 or greater than
            <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is
            <code class="constant">GL_DEPTH_COMPONENT</code>, <code class="constant">GL_DEPTH_COMPONENT16</code>,
            <code class="constant">GL_DEPTH_COMPONENT24</code>, or <code class="constant">GL_DEPTH_COMPONENT32</code> and there is no depth
            buffer.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glCopyTexImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2012-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyTexImage1D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glCopyTexImage1D glad_glCopyTexImage1D
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyTexImage2D'>OpenGL 4</a><br /><a  href='../gl3/glCopyTexImage2D'>OpenGL 3</a><br /><a  href='../gl2/glCopyTexImage2D'>OpenGL 2</a><br /><a  href='../es3/glCopyTexImage2D'>OpenGL ES 3</a><br /><a  href='../es2/glCopyTexImage2D'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glCopyTexImage2D</h1>
    <div class="refentry" id="glCopyTexImage2D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyTexImage2D — copy pixels into a 2D texture image</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTexImage2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">internalformat</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">border</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target texture.
                    Must be <code class="constant">GL_TEXTURE_2D</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>, or
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>internalformat</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the internal format of the texture.
                    Must be one of the following symbolic constants:
                    <code class="constant">GL_COMPRESSED_RED</code>,
                    <code class="constant">GL_COMPRESSED_RG</code>,
                    <code class="constant">GL_COMPRESSED_RGB</code>,
                    <code class="constant">GL_COMPRESSED_RGBA</code>.
                    <code class="constant">GL_COMPRESSED_SRGB</code>,
                    <code class="constant">GL_COMPRESSED_SRGB_ALPHA</code>.
                    <code class="constant">GL_DEPTH_COMPONENT</code>,
                    <code class="constant">GL_DEPTH_COMPONENT16</code>,
                    <code class="constant">GL_DEPTH_COMPONENT24</code>,
                    <code class="constant">GL_DEPTH_COMPONENT32</code>,
                    <code class="constant">GL_STENCIL_INDEX8</code>,
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_R3_G3_B2</code>,
                    <code class="constant">GL_RGB4</code>,
                    <code class="constant">GL_RGB5</code>,
                    <code class="constant">GL_RGB8</code>,
                    <code class="constant">GL_RGB10</code>,
                    <code class="constant">GL_RGB12</code>,
                    <code class="constant">GL_RGB16</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_RGBA2</code>,
                    <code class="constant">GL_RGBA4</code>,
                    <code class="constant">GL_RGB5_A1</code>,
                    <code class="constant">GL_RGBA8</code>,
                    <code class="constant">GL_RGB10_A2</code>,
                    <code class="constant">GL_RGBA12</code>,
                    <code class="constant">GL_RGBA16</code>,
                    <code class="constant">GL_SRGB</code>,
                    <code class="constant">GL_SRGB8</code>,
                    <code class="constant">GL_SRGB_ALPHA</code>, or
                    <code class="constant">GL_SRGB8_ALPHA8</code>.
                </p>
            </dd>
            <dt>
              <span class="term"><em class="parameter"><code>x</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>y</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specify the window coordinates of the lower left corner
                    of the rectangular region of pixels to be copied.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>border</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Must be 0.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glCopyTexImage2D</code> defines a two-dimensional texture image, or cube-map texture image
            with pixels from the current
            <code class="constant">GL_READ_BUFFER</code>.
        </p>
        <p>
            The screen-aligned pixel rectangle with lower left corner at (<em class="parameter"><code>x</code></em>,
            <em class="parameter"><code>y</code></em>) and with a width of
            <math overflow="scroll">
                <mi mathvariant="italic">width</mi>
            </math>
            and a height of
            <math overflow="scroll">
                <mi mathvariant="italic">height</mi>
            </math>
            defines the texture array
            at the mipmap level specified by <em class="parameter"><code>level</code></em>.
            <em class="parameter"><code>internalformat</code></em> specifies the internal format of the texture array.
        </p>
        <p>
            The pixels in the rectangle are processed exactly as if
            <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a> had been called, but the process stops just before
            final conversion.
            At this point all pixel component values are clamped to the range
            <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math>
            and then converted to the texture's internal format for storage in the texel
            array.
        </p>
        <p>
            Pixel ordering is such that lower
            <math overflow="scroll"><mi mathvariant="italic">x</mi></math>
            and
            <math overflow="scroll"><mi mathvariant="italic">y</mi></math>
            screen coordinates correspond to
            lower
            <math overflow="scroll"><mi mathvariant="italic">s</mi></math>
            and
            <math overflow="scroll"><mi mathvariant="italic">t</mi></math>
            texture coordinates.
        </p>
        <p>
            If any of the pixels within the specified rectangle of the current
            <code class="constant">GL_READ_BUFFER</code> are outside the window associated with the current
            rendering context, then the values obtained for those pixels are undefined.
        </p>
        <p>
            When <em class="parameter"><code>internalformat</code></em> is one of the sRGB  types, the GL does not automatically convert the source pixels to the sRGB color space.  In this case, the <code class="function">glPixelMap</code> function can be used to accomplish the conversion.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            1, 2, 3, and 4 are not accepted values for <em class="parameter"><code>internalformat</code></em>.
        </p>
        <p>
            An image with height or width of 0 indicates a NULL texture.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX8</code> is accepted for <em class="parameter"><code>internalformat</code></em> only
            if the GL version is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>target</code></em> is not <code class="constant">GL_TEXTURE_2D</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>, or
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater
            than
            <math overflow="scroll">

                <mrow>
                    <msub><mi mathvariant="italic">log</mi>
                    <mn>2</mn>
                    </msub>
                    <mo>⁢</mo>
                    <mi mathvariant="italic">max</mi>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">max</mi></math>
            is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em> is less than 0
            or greater than
            <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>border</code></em> is not 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>internalformat</code></em> is not an
            accepted format.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>internalformat</code></em> is
            <code class="constant">GL_DEPTH_COMPONENT</code>, <code class="constant">GL_DEPTH_COMPONENT16</code>,
            <code class="constant">GL_DEPTH_COMPONENT24</code>, or <code class="constant">GL_DEPTH_COMPONENT32</code> and there is no depth
            buffer.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glCopyTexImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2012-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyTexImage2D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glCopyTexImage2D glad_glCopyTexImage2D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyTexSubImage1D'>OpenGL 4</a><br /><a  href='../gl3/glCopyTexSubImage1D'>OpenGL 3</a><br /><a  href='../gl2/glCopyTexSubImage1D'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glCopyTexSubImage1D</h1>
    <div class="refentry" id="glCopyTexSubImage1D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyTexSubImage1D, glCopyTextureSubImage1D — copy a one-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTexSubImage1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTextureSubImage1D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture object is bound for
          <code class="function">glCopyTexSubImage1D</code> function. Must be
          <code class="constant">GL_TEXTURE_1D</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCopyTextureSubImage1D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texel offset within the texture array.</p>
            </dd>
            <dt>
              <span class="term"><em class="parameter"><code>x</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>y</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specify the window coordinates of the left corner of the row
          of pixels to be copied.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p><code class="function">glCopyTexSubImage1D</code> and
    <code class="function">glCopyTextureSubImage1D</code> replace a portion of a
    one-dimensional texture image with pixels from the current
    <code class="constant">GL_READ_BUFFER</code> (rather than from Main memory, as is
    the case for <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>). For <code class="function">glCopyTexSubImage1D</code>, the
    texture object that is bound to <em class="parameter"><code>target</code></em> will be used
    for the process. For <code class="function">glCopyTextureSubImage1D</code>,
    <em class="parameter"><code>texture</code></em> tells which texture object should be used
    for the purpose of the call. </p>
        <p>The screen-aligned pixel row with left corner at
    (<em class="parameter"><code>x</code></em>,\ <em class="parameter"><code>y</code></em>), and with length
    <em class="parameter"><code>width</code></em> replaces the portion of the texture array
    with x indices <em class="parameter"><code>xoffset</code></em> through
<math overflow="scroll">


          <mrow>
            <mi mathvariant="italic">xoffset</mi>

            <mo>+</mo>

            <mi mathvariant="italic">width</mi>

            <mo>-</mo>

            <mn>1</mn>
          </mrow>
        </math>, inclusive. The destination in the texture array may
    not include any texels outside the texture array as it was originally
    specified.</p>
        <p>The pixels in the row are processed exactly as if <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a> had been called, but the process stops just before final
    conversion. At this point, all pixel component values are clamped to the
    range <math overflow="scroll">


          <mfenced close="]" open="[">
            <mn>0</mn>

            <mn>1</mn>
          </mfenced>
        </math> and then converted to the texture's internal format
    for storage in the texel array.</p>
        <p>It is not an error to specify a subtexture with zero width, but such
    a specification has no effect. If any of the pixels within the specified
    row of the current <code class="constant">GL_READ_BUFFER</code> are outside the
    read window associated with the current rendering context, then the values
    obtained for those pixels are undefined.</p>
        <p>No change is made to the <span class="emphasis"><em>internalformat</em></span> or
    <span class="emphasis"><em>width</em></span> parameters of the specified texture array or to
    texel values outside the specified subregion.</p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>The <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> mode affects texture images.</p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated by
    <code class="function">glCopyTexSubImage1D</code> if <em class="parameter"><code>target</code></em>
    is not <code class="constant">GL_TEXTURE_1D</code>.</p>
        <p><code class="constant">GL_INVALID_FRAMEBUFFER_OPERATION</code> is generated
    if the object bound to <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code> is
    not framebuffer complete.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCopyTextureSubImage1D</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object, or if the effective target of <em class="parameter"><code>texture</code></em> is
    not <code class="constant">GL_TEXTURE_1D</code>.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if the
    texture array has not been defined by a previous <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>, <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>, or <a class="citerefentry" href="glTexStorage1D"><span class="citerefentry"><span class="refentrytitle">glTexStorage1D</span></span></a> operation.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>level</code></em> is less than 0.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> may be generated if
    <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">level</mi>
                    <mo>&gt;</mo>
                    <mrow>
                        <msub><mi mathvariant="italic">log</mi>
                        <mn>2</mn>
                        </msub>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <mi mathvariant="italic">max</mi>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>, where <span class="emphasis"><em>max</em></span> is the returned value
    of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,
       or
            <math overflow="scroll">


          <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mi mathvariant="italic">w</mi>
                </mrow>
            </math>, where <math overflow="scroll"><mi mathvariant="italic">w</mi></math> is the <code class="constant">GL_TEXTURE_WIDTH</code> of the
    texture image being modified.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if:</p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>the read buffer is <code class="constant">GL_NONE</code>, or</p>
            </li>
            <li class="listitem">
              <p>the value of <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code>
          is non-zero, and:</p>
              <div class="itemizedlist">
                <ul class="itemizedlist" style="list-style-type: circle; ">
                  <li class="listitem">
                    <p>the read buffer selects an attachment that has no image
                attached, or</p>
                  </li>
                  <li class="listitem">
                    <p>the effective value of
                <code class="constant">GL_SAMPLE_BUFFERS</code> for the read
                framebuffer is one.</p>
                  </li>
                </ul>
              </div>
            </li>
          </ul>
        </div>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glCopyTexSubImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glCopyTextureSubImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glReadBuffer"><span class="citerefentry"><span class="refentrytitle">glReadBuffer</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc.
            Copyright © 2012-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyTexSubImage1D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glCopyTexSubImage1D glad_glCopyTexSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glCopyTexSubImage2D'>OpenGL 4</a><br /><a  href='../gl3/glCopyTexSubImage2D'>OpenGL 3</a><br /><a  href='../gl2/glCopyTexSubImage2D'>OpenGL 2</a><br /><a  href='../es3/glCopyTexSubImage2D'>OpenGL ES 3</a><br /><a  href='../es2/glCopyTexSubImage2D'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glCopyTexSubImage2D</h1>
    <div class="refentry" id="glCopyTexSubImage2D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glCopyTexSubImage2D, glCopyTextureSubImage2D — copy a two-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTexSubImage2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glCopyTextureSubImage2D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">x</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">y</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the target to which the texture object is bound for
          <code class="function">glCopyTexSubImage2D</code> function. Must be
          <code class="constant">GL_TEXTURE_1D_ARRAY</code>,
          <code class="constant">GL_TEXTURE_2D</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
          <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>, or
          <code class="constant">GL_TEXTURE_RECTANGLE</code>.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the texture object name for
          <code class="function">glCopyTextureSubImage2D</code> function.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the level-of-detail number. Level 0 is the base
          image level. Level <span class="emphasis"><em>n</em></span> is the
          <span class="emphasis"><em>n</em></span>th mipmap reduction image.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the x direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies a texel offset in the y direction within the texture
          array.</p>
            </dd>
            <dt>
              <span class="term"><em class="parameter"><code>x</code></em>, </span>
              <span class="term">
                <em class="parameter">
                  <code>y</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specify the window coordinates of the lower left corner of the
          rectangular region of pixels to be copied.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the width of the texture subimage.</p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>Specifies the height of the texture subimage.</p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p><code class="function">glCopyTexSubImage2D</code> and
    <code class="function">glCopyTextureSubImage2D</code> replace a rectangular portion
    of a two-dimensional texture image, cube-map texture image, rectangular
    image, or a linear portion of a number of slices of a one-dimensional
    array texture with pixels from the current
    <code class="constant">GL_READ_BUFFER</code> (rather than from Main memory, as is
    the case for <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>).</p>
        <p>The screen-aligned pixel rectangle with lower left corner at
    <math overflow="scroll">

                <mfenced open="(" close=")">
                    <mi mathvariant="italic">x</mi>
                    <mi mathvariant="italic">y</mi>
                </mfenced>
            </math> and with width <em class="parameter"><code>width</code></em> and height
    <em class="parameter"><code>height</code></em> replaces the portion of the texture array
    with x indices <em class="parameter"><code>xoffset</code></em> through <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>, inclusive, and y indices
    <em class="parameter"><code>yoffset</code></em> through <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>, inclusive, at the mipmap level specified by
    <em class="parameter"><code>level</code></em>.</p>
        <p>The pixels in the rectangle are processed exactly as if
    <a class="citerefentry" href="glReadPixels"><span class="citerefentry"><span class="refentrytitle">glReadPixels</span></span></a> had been called, but the process stops just before final
    conversion. At this point, all pixel component values are clamped to the
    range <math overflow="scroll">

                <mfenced open="[" close="]">
                    <mn>0</mn>
                    <mn>1</mn>
                </mfenced>
            </math> and then converted to the texture's internal format
    for storage in the texel array.</p>
        <p>The destination rectangle in the texture array may not include any
    texels outside the texture array as it was originally specified. It is not
    an error to specify a subtexture with zero width or height, but such a
    specification has no effect.</p>
        <p>When <em class="parameter"><code>target</code></em> is
    <code class="constant">GL_TEXTURE_1D_ARRAY</code> then the y coordinate and height
    are treated as the start slice and number of slices to modify.</p>
        <p>If any of the pixels within the specified rectangle of the current
    <code class="constant">GL_READ_BUFFER</code> are outside the read window associated
    with the current rendering context, then the values obtained for those
    pixels are undefined.</p>
        <p>No change is made to the <span class="emphasis"><em>internalformat</em></span>,
    <span class="emphasis"><em>width</em></span>, or <span class="emphasis"><em>height</em></span>, parameters of
    the specified texture array or to texel values outside the specified
    subregion.</p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> modes affect texture images.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p><code class="constant">GL_INVALID_ENUM</code> is generated if
    <em class="parameter"><code>target</code></em> is not <code class="constant">GL_TEXTURE_2D</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>,
    <code class="constant">GL_TEXTURE_1D_ARRAY</code>, or
    <code class="constant">GL_RECTANGLE</code>.</p>
        <p><code class="constant">GL_INVALID_FRAMEBUFFER_OPERATION</code> is generated
    if the object bound to <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code> is
    not framebuffer complete.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if the
    texture array has not been defined by a previous <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>, <a class="citerefentry" href="glTexStorage2D"><span class="citerefentry"><span class="refentrytitle">glTexStorage2D</span></span></a> or <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a> operation.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCopyTextureSubImage2D</code> if
    <em class="parameter"><code>texture</code></em> is not the name of an existing texture
    object.</p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated by
    <code class="function">glCopyTextureSubImage2D</code> if the effective target of
    texture does not correspond to one of the texture targets supported by the
    function.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <em class="parameter"><code>level</code></em> is less than 0.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if the effective
    target is <code class="constant">GL_TEXTURE_RECTANGLE</code> and
    <em class="parameter"><code>level</code></em> is not zero.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> may be generated if
    <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">level</mi>
                    <mo>&gt;</mo>
                    <mrow>
                        <msub><mi mathvariant="italic">log</mi>
                        <mn>2</mn>
                        </msub>
                        <mo>⁡</mo>
                        <mfenced open="(" close=")">
                            <mi mathvariant="italic">max</mi>
                        </mfenced>
                    </mrow>
                </mrow>
            </math>, where <math overflow="scroll"><mi mathvariant="italic">max</mi></math> is the returned value of
    <code class="constant">GL_MAX_TEXTURE_SIZE</code>.</p>
        <p><code class="constant">GL_INVALID_VALUE</code> is generated if
    <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>, <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mi mathvariant="italic">w</mi>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>&lt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">yoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">height</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mn>0</mn>
                </mrow>
            </math>,, where <math overflow="scroll"><mi mathvariant="italic">w</mi></math> is the <code class="constant">GL_TEXTURE_WIDTH</code>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>
            is the <code class="constant">GL_TEXTURE_HEIGHT</code> and
            of the texture image being modified.
        </p>
        <p><code class="constant">GL_INVALID_OPERATION</code> is generated if:</p>
        <div class="itemizedlist">
          <ul class="itemizedlist" style="list-style-type: disc; ">
            <li class="listitem">
              <p>the read buffer is <code class="constant">GL_NONE</code>, or</p>
            </li>
            <li class="listitem">
              <p>the value of <code class="constant">GL_READ_FRAMEBUFFER_BINDING</code>
          is non-zero, and:</p>
              <div class="itemizedlist">
                <ul class="itemizedlist" style="list-style-type: circle; ">
                  <li class="listitem">
                    <p>the read buffer selects an attachment that has no image
                attached, or</p>
                  </li>
                  <li class="listitem">
                    <p>the effective value of
                <code class="constant">GL_SAMPLE_BUFFERS</code> for the read
                framebuffer is one.</p>
                  </li>
                </ul>
              </div>
            </li>
          </ul>
        </div>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glCopyTexSubImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glCopyTextureSubImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glReadBuffer"><span class="citerefentry"><span class="refentrytitle">glReadBuffer</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006
            Silicon Graphics, Inc. Copyright © 2012-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glCopyTexSubImage2D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glCopyTexSubImage2D glad_glCopyTexSubImage2D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexSubImage1D'>OpenGL 4</a><br /><a  href='../gl3/glTexSubImage1D'>OpenGL 3</a><br /><a  href='../gl2/glTexSubImage1D'>OpenGL 2</a><br /></div>
      <h1 id="command_title">glTexSubImage1D</h1>
    <div class="refentry" id="glTexSubImage1D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexSubImage1D, glTextureSubImage1D — specify a one-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexSubImage1D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTextureSubImage1D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the texture is bound for
                    <code class="function">glTexSubImage1D</code>.
                    Must be <code class="constant">GL_TEXTURE_1D</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the texture object name for
                    <code class="function">glTextureSubImage1D</code>. The effective
                    target of <em class="parameter"><code>texture</code></em> must be one of
                    the valid <em class="parameter"><code>target</code></em> values above.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the x direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_BGR</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_DEPTH_COMPONENT</code>, and
                    <code class="constant">GL_STENCIL_INDEX</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>type</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the data type of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>,
                    <code class="constant">GL_SHORT</code>,
                    <code class="constant">GL_UNSIGNED_INT</code>,
                    <code class="constant">GL_INT</code>,
                    <code class="constant">GL_FLOAT</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, and
                    <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pixels</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing maps a portion of a specified texture image
            onto each graphical primitive for which texturing is enabled.
            To enable or disable one-dimensional texturing, call <a class="citerefentry" href="glEnable"><span class="citerefentry"><span class="refentrytitle">glEnable</span></span></a>
            and <a class="citerefentry" href="glDisable"><span class="citerefentry"><span class="refentrytitle">glDisable</span></span></a> with argument <code class="constant">GL_TEXTURE_1D</code>.
        </p>
        <p>
            <code class="function">glTexSubImage1D</code> and
            <code class="function">glTextureSubImage1D</code> redefine a contiguous
            subregion of an existing one-dimensional texture image.
            The texels referenced by <em class="parameter"><code>pixels</code></em> replace the portion of the
            existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.
            This region may not include any texels outside the range of the
            texture array as it was originally specified.
            It is not an error to specify a subtexture with width of 0, but
            such a specification has no effect.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>pixels</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> modes affect texture images.
        </p>
        <p>
            <code class="function">glTexSubImage1D</code> and
            <code class="function">glTextureSubImage1D</code> specify a
            one-dimensional subtexture for the current texture unit,
            specified with
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX</code> is accepted for <em class="parameter"><code>format</code></em> only if the GL version
            is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>target</code></em> or the effective target of
            <em class="parameter"><code>texture</code></em> is not one of the allowable
            values.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glTextureSubImage1D</code> if
            <em class="parameter"><code>texture</code></em> is not the name of an existing
            texture object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>format</code></em> is not an accepted
            format constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>type</code></em> is not a type constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater
            than
            <math overflow="scroll">

                <msub><mi mathvariant="italic">log</mi>
                <mn>2</mn>
                </msub>
            </math>
            <span class="emphasis"><em>max</em></span>,
            where <span class="emphasis"><em>max</em></span> is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            or if
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">w</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            is the <code class="constant">GL_TEXTURE_WIDTH</code>, and
            <math overflow="scroll"><mi mathvariant="italic">b</mi></math>
            is
            the width of the <code class="constant">GL_TEXTURE_BORDER</code>
            of the texture image being modified.
            Note that
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            includes twice the border width.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if the texture array has not
            been defined by a previous <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a> operation.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
            <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>, or
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>
            and <em class="parameter"><code>format</code></em> is not <code class="constant">GL_RGB</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
            <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, or
            <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>
            and <em class="parameter"><code>format</code></em> is neither <code class="constant">GL_RGBA</code> nor <code class="constant">GL_BGRA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>format</code></em> is <code class="constant">GL_STENCIL_INDEX</code>
            and the base internal format is not <code class="constant">GL_STENCIL_INDEX</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and <em class="parameter"><code>pixels</code></em> is not evenly divisible
            into the number of bytes needed to store in memory a datum indicated by <em class="parameter"><code>type</code></em>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glTexSubImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glTextureSubImage1D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexSubImage1D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glTexSubImage1D glad_glTexSubImage1D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glTexSubImage2D'>OpenGL 4</a><br /><a  href='../gl3/glTexSubImage2D'>OpenGL 3</a><br /><a  href='../gl2/glTexSubImage2D'>OpenGL 2</a><br /><a  href='../es3/glTexSubImage2D'>OpenGL ES 3</a><br /><a  href='../es2/glTexSubImage2D'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glTexSubImage2D</h1>
    <div class="refentry" id="glTexSubImage2D">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glTexSubImage2D, glTextureSubImage2D — specify a two-dimensional texture subimage</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTexSubImage2D</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLvoid * <var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glTextureSubImage2D</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">level</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">xoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLint <var class="pdparam">yoffset</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">width</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLsizei <var class="pdparam">height</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">format</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLenum <var class="pdparam">type</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const void *<var class="pdparam">pixels</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the texture is bound
                    for <code class="function">glTexSubImage2D</code>.
                    Must be <code class="constant">GL_TEXTURE_2D</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>,
                    or <code class="constant">GL_TEXTURE_1D_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the texture object name for
                    <code class="function">glTextureSubImage2D</code>. The effective
                    target of <em class="parameter"><code>texture</code></em> must be one of
                    the valid <em class="parameter"><code>target</code></em> values above.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>level</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the level-of-detail number.
                    Level 0 is the base image level.
                    Level <span class="emphasis"><em>n</em></span> is the <span class="emphasis"><em>n</em></span>th mipmap reduction image.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>xoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the x direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>yoffset</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a texel offset in the y direction within the texture array.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>width</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the width of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>height</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the height of the texture subimage.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>format</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the format of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_RED</code>,
                    <code class="constant">GL_RG</code>,
                    <code class="constant">GL_RGB</code>,
                    <code class="constant">GL_BGR</code>,
                    <code class="constant">GL_RGBA</code>,
                    <code class="constant">GL_BGRA</code>,
                    <code class="constant">GL_DEPTH_COMPONENT</code>, and
                    <code class="constant">GL_STENCIL_INDEX</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>type</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the data type of the pixel data.
                    The following symbolic values are accepted:
                    <code class="constant">GL_UNSIGNED_BYTE</code>,
                    <code class="constant">GL_BYTE</code>,
                    <code class="constant">GL_UNSIGNED_SHORT</code>,
                    <code class="constant">GL_SHORT</code>,
                    <code class="constant">GL_UNSIGNED_INT</code>,
                    <code class="constant">GL_INT</code>,
                    <code class="constant">GL_FLOAT</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
                    <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
                    <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
                    <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
                    <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, and
                    <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>pixels</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a pointer to the image data in memory.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            Texturing maps a portion of a specified texture image
            onto each graphical primitive for which texturing is enabled.
        </p>
        <p>
            <code class="function">glTexSubImage2D</code> and
            <code class="function">glTextureSubImage2D</code> redefine a contiguous
            subregion of an existing two-dimensional or one-dimensional
            array texture image.
            The texels referenced by <em class="parameter"><code>pixels</code></em> replace the portion of the
            existing texture array with x indices <em class="parameter"><code>xoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">width</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive,
            and y indices <em class="parameter"><code>yoffset</code></em> and
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>+</mo>
                    <mi mathvariant="italic">height</mi>
                    <mo>-</mo>
                    <mn>1</mn>
                </mrow>
            </math>,
            inclusive.
            This region may not include any texels outside the range of the
            texture array as it was originally specified.
            It is not an error to specify a subtexture with zero width or height, but
            such a specification has no effect.
        </p>
        <p>
            If a non-zero named buffer object is bound to the <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target
            (see <a class="citerefentry" href="glBindBuffer"><span class="citerefentry"><span class="refentrytitle">glBindBuffer</span></span></a>) while a texture image is
            specified, <em class="parameter"><code>pixels</code></em> is treated as a byte offset into the buffer object's data store.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a> modes affect texture images.
        </p>
        <p>
            <code class="function">glTexSubImage2D</code> and
            <code class="function">glTextureSubImage3D</code> specify a
            two-dimensional subtexture for the current texture unit,
            specified with
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>.
        </p>
        <p>
            <code class="constant">GL_STENCIL_INDEX</code> is accepted for <em class="parameter"><code>format</code></em> only if the GL version
            is 4.4 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if
            <em class="parameter"><code>target</code></em> or the effective target of
            <em class="parameter"><code>texture</code></em> is not
            <code class="constant">GL_TEXTURE_2D</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_X</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Y</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_POSITIVE_Z</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_NEGATIVE_Z</code>, or
            <code class="constant">GL_TEXTURE_1D_ARRAY</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated by
            <code class="function">glTextureSubImage2D</code> if
            <em class="parameter"><code>texture</code></em> is not the name of an existing
            texture object.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>format</code></em> is not an accepted
            format constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>type</code></em> is not a type constant.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>level</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> may be generated if <em class="parameter"><code>level</code></em> is greater
            than
            <math overflow="scroll">

                <msub><mi mathvariant="italic">log</mi>
                <mn>2</mn>
                </msub>
            </math>
            <span class="emphasis"><em>max</em></span>,
            where <span class="emphasis"><em>max</em></span> is the returned value of <code class="constant">GL_MAX_TEXTURE_SIZE</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">xoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">xoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">width</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">w</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            <math overflow="scroll">

                <mrow>
                    <mi mathvariant="italic">yoffset</mi>
                    <mo>&lt;</mo>
                    <mrow>
                        <mo>-</mo>
                        <mi mathvariant="italic">b</mi>
                    </mrow>
                </mrow>
            </math>,
            or
            <math overflow="scroll">

                <mrow>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">yoffset</mi>
                            <mo>+</mo>
                            <mi mathvariant="italic">height</mi>
                        </mrow>
                    </mfenced>
                    <mo>&gt;</mo>
                    <mfenced open="(" close=")">
                        <mrow>
                            <mi mathvariant="italic">h</mi>
                            <mo>-</mo>
                            <mi mathvariant="italic">b</mi>
                        </mrow>
                    </mfenced>
                </mrow>
            </math>,
            where
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            is the <code class="constant">GL_TEXTURE_WIDTH</code>,
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>
            is the <code class="constant">GL_TEXTURE_HEIGHT</code>, and
            <math overflow="scroll"><mi mathvariant="italic">b</mi></math>
            is the border width
            of the texture image being modified.
            Note that
            <math overflow="scroll"><mi mathvariant="italic">w</mi></math>
            and
            <math overflow="scroll"><mi mathvariant="italic">h</mi></math>
            include twice the border width.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>width</code></em> or <em class="parameter"><code>height</code></em> is less than 0.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if the texture array has not
            been defined by a previous <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a> operation.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_BYTE_3_3_2</code>,
            <code class="constant">GL_UNSIGNED_BYTE_2_3_3_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5</code>, or
            <code class="constant">GL_UNSIGNED_SHORT_5_6_5_REV</code>
            and <em class="parameter"><code>format</code></em> is not <code class="constant">GL_RGB</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>type</code></em> is one of
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4</code>,
            <code class="constant">GL_UNSIGNED_SHORT_4_4_4_4_REV</code>,
            <code class="constant">GL_UNSIGNED_SHORT_5_5_5_1</code>,
            <code class="constant">GL_UNSIGNED_SHORT_1_5_5_5_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8</code>,
            <code class="constant">GL_UNSIGNED_INT_8_8_8_8_REV</code>,
            <code class="constant">GL_UNSIGNED_INT_10_10_10_2</code>, or
            <code class="constant">GL_UNSIGNED_INT_2_10_10_10_REV</code>
            and <em class="parameter"><code>format</code></em> is neither <code class="constant">GL_RGBA</code> nor <code class="constant">GL_BGRA</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>format</code></em> is <code class="constant">GL_STENCIL_INDEX</code>
            and the base internal format is not <code class="constant">GL_STENCIL_INDEX</code>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the buffer object's data store is currently mapped.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and the data would be unpacked from the buffer
            object such that the memory reads required would exceed the data store size.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if a non-zero buffer object name is bound to the
            <code class="constant">GL_PIXEL_UNPACK_BUFFER</code> target and <em class="parameter"><code>pixels</code></em> is not evenly divisible
            into the number of bytes needed to store in memory a datum indicated by <em class="parameter"><code>type</code></em>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGetTexImage"><span class="citerefentry"><span class="refentrytitle">glGetTexImage</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_PIXEL_UNPACK_BUFFER_BINDING</code>
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://www.songho.ca/opengl/gl_pbo.html">Songho - OpenGL Pixel Buffer Object (PBO)</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glTexSubImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glTextureSubImage2D</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage2D</span></span></a>,
            <a class="citerefentry" href="glCopyTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glCopyTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glPixelStore"><span class="citerefentry"><span class="refentrytitle">glPixelStore</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage1D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage1D</span></span></a>,
            <a class="citerefentry" href="glTexSubImage3D"><span class="citerefentry"><span class="refentrytitle">glTexSubImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glTexSubImage2D.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glTexSubImage2D glad_glTexSubImage2D
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glBindTexture'>OpenGL 4</a><br /><a  href='../gl3/glBindTexture'>OpenGL 3</a><br /><a  href='../gl2/glBindTexture'>OpenGL 2</a><br /><a  href='../es3/glBindTexture'>OpenGL ES 3</a><br /><a  href='../es2/glBindTexture'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glBindTexture</h1>
    <div class="refentry" id="glBindTexture">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glBindTexture — bind a named texture to a texturing target</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glBindTexture</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">target</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">texture</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>target</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the target to which the texture is bound.
                    Must be one of
                    <code class="constant">GL_TEXTURE_1D</code>,
                    <code class="constant">GL_TEXTURE_2D</code>,
                    <code class="constant">GL_TEXTURE_3D</code>,
                    <code class="constant">GL_TEXTURE_1D_ARRAY</code>,
                    <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
                    <code class="constant">GL_TEXTURE_RECTANGLE</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP</code>,
                    <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>,
                    <code class="constant">GL_TEXTURE_BUFFER</code>,
                    <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> or
                    <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code>.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the name of a texture.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glBindTexture</code> lets you create or use a named texture. Calling <code class="function">glBindTexture</code> with
            <em class="parameter"><code>target</code></em> set to
            <code class="constant">GL_TEXTURE_1D</code>,
            <code class="constant">GL_TEXTURE_2D</code>,
            <code class="constant">GL_TEXTURE_3D</code>,
            <code class="constant">GL_TEXTURE_1D_ARRAY</code>,
            <code class="constant">GL_TEXTURE_2D_ARRAY</code>,
            <code class="constant">GL_TEXTURE_RECTANGLE</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP</code>,
            <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code>,
            <code class="constant">GL_TEXTURE_BUFFER</code>,
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> or
            <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code>
            and <em class="parameter"><code>texture</code></em> set to the name of the new texture binds the texture name to the target.
            When a texture is bound to a target, the previous binding for that target is automatically broken.
        </p>
        <p>
            Texture names are unsigned integers. The value zero is reserved to
            represent the default texture for each texture target.
            Texture names and the corresponding texture contents are local to
            the shared object space of the current GL rendering context;
            two rendering contexts share texture names only if they
            explicitly enable sharing between contexts through the appropriate GL windows interfaces functions.
        </p>
        <p>
            You must use <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a> to generate a set of new texture names.
        </p>
        <p>
            When a texture is first bound, it assumes the specified target:
            A texture first bound to <code class="constant">GL_TEXTURE_1D</code> becomes one-dimensional texture, a
            texture first bound to <code class="constant">GL_TEXTURE_2D</code> becomes two-dimensional texture, a
            texture first bound to <code class="constant">GL_TEXTURE_3D</code> becomes three-dimensional texture, a
            texture first bound to <code class="constant">GL_TEXTURE_1D_ARRAY</code> becomes one-dimensional array texture, a
            texture first bound to <code class="constant">GL_TEXTURE_2D_ARRAY</code> becomes two-dimensional array texture, a
            texture first bound to <code class="constant">GL_TEXTURE_RECTANGLE</code> becomes rectangle texture, a
            texture first bound to <code class="constant">GL_TEXTURE_CUBE_MAP</code> becomes a cube-mapped texture, a
            texture first bound to <code class="constant">GL_TEXTURE_CUBE_MAP_ARRAY</code> becomes a cube-mapped array texture, a
            texture first bound to <code class="constant">GL_TEXTURE_BUFFER</code> becomes a buffer texture, a
            texture first bound to <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> becomes a two-dimensional multisampled texture, and a
            texture first bound to <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code> becomes a two-dimensional multisampled array texture.
            The state of a one-dimensional texture immediately after it is first bound is equivalent to the state of the
            default <code class="constant">GL_TEXTURE_1D</code> at GL initialization, and similarly for the other texture types.
        </p>
        <p>
            While a texture is bound, GL operations on the target to which it is
            bound affect the bound texture, and queries of the target to which it
            is bound return state from the bound texture.
            In effect, the texture targets become aliases for the textures currently
            bound to them, and the texture name zero refers to the default textures
            that were bound to them at initialization.
        </p>
        <p>
            A texture binding created with <code class="function">glBindTexture</code> remains active until a different
            texture is bound to the same target, or until the bound texture is
            deleted with <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>.
        </p>
        <p>
            Once created, a named texture may be re-bound to its same original target as often as needed.
            It is usually much faster to use <code class="function">glBindTexture</code> to bind an existing named
            texture to one of the texture targets than it is to reload the texture image
            using <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>, <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a> or another similar function.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            The <code class="constant">GL_TEXTURE_2D_MULTISAMPLE</code> and <code class="constant">GL_TEXTURE_2D_MULTISAMPLE_ARRAY</code> targets are available
            only if the GL version is 3.2 or higher.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>target</code></em> is not one of the allowable
            values.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>target</code></em> is not a name returned from
            a previous call to <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>.
        </p>
        <p>
            <code class="constant">GL_INVALID_OPERATION</code> is generated if <em class="parameter"><code>texture</code></em> was previously created with a target
            that doesn't match that of <em class="parameter"><code>target</code></em>.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a> with argument <code class="constant">GL_TEXTURE_BINDING_1D</code>,
            <code class="constant">GL_TEXTURE_BINDING_2D</code>, <code class="constant">GL_TEXTURE_BINDING_3D</code>, <code class="constant">GL_TEXTURE_BINDING_1D_ARRAY</code>,
            <code class="constant">GL_TEXTURE_BINDING_2D_ARRAY</code>, <code class="constant">GL_TEXTURE_BINDING_RECTANGLE</code>,
            <code class="constant">GL_TEXTURE_BINDING_BUFFER</code>, <code class="constant">GL_TEXTURE_BINDING_CUBE_MAP</code>,
            <code class="constant">GL_TEXTURE_BINDING_CUBE_MAP_ARRAY</code>,
            <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE</code>,
            or <code class="constant">GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY</code>.
        </p>
      </div>
      <div class='refsect1' id='examples'><h2>Examples</h2><div class='example'>Create a framebuffer object with a texture-based color attachment and a texture-based depth attachment. Using texture-based attachments allows sampling of those textures in shaders.<pre class='programlisting'><span class='codecomment'>// fbo_width and fbo_height are the desired width and height of the FBO.</span>
<span class='codecomment'>// For Opengl &lt;= 4.4 or <span class='ckeyword'>if</span> the <span class='constant'>GL_ARB_</span>texture_non_power_of_two extension</span>
<span class='codecomment'>// is present, fbo_width and fbo_height can be values other than 2^n <span class='ckeyword'>for</span></span>
<span class='codecomment'>// some integer n.</span>

<span class='codecomment'>// Build the texture that will serve as the color attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> texture_map;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;texture_map);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, texture_map);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);

<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_RGBA</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_RGBA</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);

<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the texture that will serve as the depth attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> depth_texture;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;depth_texture);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, depth_texture);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the framebuffer.</span>
<span class='ckeyword'>GLuint</span> framebuffer;
<a href='../gl4/glGenFramebuffers'>glGenFramebuffers</a>(1, &amp;framebuffer);
<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, (<span class='ckeyword'>GLuint</span>)framebuffer);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_COLOR_ATTACHMENT0</span>, <span class='constant'>GL_TEXTURE_2D</span>, texture_map, 0);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_DEPTH_ATTACHMENT</span>, <span class='constant'>GL_TEXTURE_2D</span>, depth_texture, 0);

<span class='ckeyword'>GLenum</span> status = <a href='../gl4/glCheckFramebufferStatus'>glCheckFramebufferStatus</a>(<span class='constant'>GL_FRAMEBUFFER</span>);
<span class='ckeyword'>if</span> (status != <span class='constant'>GL_FRAMEBUFFER_COMPLETE</span>)
    <span class='codecomment'>// Error</span>

<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, 0);</pre></div><div class='example'>Create a texture object with linear mipmaps and edge clamping.<pre class='programlisting'><span class='ckeyword'>GLuint</span> texture_id;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;texture_id);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, texture_id);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_LINEAR_MIPMAP_LINEAR</span>);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);

<span class='codecomment'>// texture_data is the source data of your texture, in this <span class='ckeyword'>case</span></span>
<span class='codecomment'>// its size is <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>unsigned</span> <span class='ckeyword'>char</span>) * texture_width * texture_height * 4</span>
<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_RGBA</span>, texture_width, texture_height, 0, <span class='constant'>GL_RGBA</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, texture_data);
<a href='../gl4/glGenerateMipmap'>glGenerateMipmap</a>(<span class='constant'>GL_TEXTURE_2D</span>); <span class='codecomment'>// Unavailable in OpenGL 2.1, use gluBuild2DMipmaps() insteads.</span>

<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);
</pre></div></div><div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://antongerdelan.net/opengl/cubemaps.html">Anton Gerdelan - Cube Maps: Sky Boxes and Environment Mapping</a><br /><a href="https://www.oldunreal.com/editing/s3tc/ARB_texture_compression.pdf">S&eacute;bastien Domin&eacute; - Using Texture Compression in OpenGL</a><br /><a href="https://www.songho.ca/opengl/gl_pbo.html">Songho - OpenGL Pixel Buffer Object (PBO)</a><br /><a href="https://open.gl/framebuffers">open.gl - Framebuffers</a><br /><a href="https://open.gl/geometry">open.gl - Geometry Shaders</a><br /><a href="https://open.gl/textures">open.gl - Textures Objects and Parameters</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/">opengl-tutorial.org - Tutorial 13 : Normal Mapping</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-14-render-to-texture/">opengl-tutorial.org - Tutorial 14 : Render To Texture</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-16-shadow-mapping/">opengl-tutorial.org - Tutorial 16 : Shadow mapping</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/">opengl-tutorial.org - Tutorial 5 : A Textured Cube</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glBindTexture</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>,
            <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glIsTexture"><span class="citerefentry"><span class="refentrytitle">glIsTexture</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage2DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage2DMultisample</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexImage3DMultisample"><span class="citerefentry"><span class="refentrytitle">glTexImage3DMultisample</span></span></a>,
            <a class="citerefentry" href="glTexBuffer"><span class="citerefentry"><span class="refentrytitle">glTexBuffer</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glBindTexture.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glBindTexture glad_glBindTexture
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDeleteTextures'>OpenGL 4</a><br /><a  href='../gl3/glDeleteTextures'>OpenGL 3</a><br /><a  href='../gl2/glDeleteTextures'>OpenGL 2</a><br /><a  href='../es3/glDeleteTextures'>OpenGL ES 3</a><br /><a  href='../es2/glDeleteTextures'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glDeleteTextures</h1>
    <div class="refentry" id="glDeleteTextures">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glDeleteTextures — delete named textures</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDeleteTextures</strong>(</code>
              </td>
              <td>GLsizei <var class="pdparam">n</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>const GLuint * <var class="pdparam">textures</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>n</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of textures to be deleted.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>textures</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies an array of textures to be deleted.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glDeleteTextures</code> deletes <em class="parameter"><code>n</code></em> textures named by the elements of the array <em class="parameter"><code>textures</code></em>.
            After a texture is deleted, it has no contents or dimensionality,
            and its name is free for reuse (for example by <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>).
            If a texture that is currently bound is deleted, the binding reverts
            to 0 (the default texture).
        </p>
        <p>
            <code class="function">glDeleteTextures</code> silently ignores 0's and names that do not correspond to
            existing textures.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>n</code></em> is negative.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glIsTexture"><span class="citerefentry"><span class="refentrytitle">glIsTexture</span></span></a>
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glDeleteTextures</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDeleteTextures.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glDeleteTextures glad_glDeleteTextures
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glGenTextures'>OpenGL 4</a><br /><a  href='../gl3/glGenTextures'>OpenGL 3</a><br /><a  href='../gl2/glGenTextures'>OpenGL 2</a><br /><a  href='../es3/glGenTextures'>OpenGL ES 3</a><br /><a  href='../es2/glGenTextures'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glGenTextures</h1>
    <div class="refentry" id="glGenTextures">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glGenTextures — generate texture names</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glGenTextures</strong>(</code>
              </td>
              <td>GLsizei <var class="pdparam">n</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint * <var class="pdparam">textures</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>n</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the number of texture names to be generated.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>textures</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies an array in which the generated texture names are stored.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glGenTextures</code> returns <em class="parameter"><code>n</code></em> texture names in <em class="parameter"><code>textures</code></em>.
            There is no guarantee that the names form a contiguous set of integers;
            however, it is guaranteed that none of the returned names was in use
            immediately before the call to <code class="function">glGenTextures</code>.
        </p>
        <p>
            The generated textures have no dimensionality; they assume the dimensionality
            of the texture target to which they are first bound
            (see <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>).
        </p>
        <p>
            Texture names returned by a call to <code class="function">glGenTextures</code> are not returned by
            subsequent calls, unless they are first deleted with
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>.
        </p>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated if <em class="parameter"><code>n</code></em> is negative.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glIsTexture"><span class="citerefentry"><span class="refentrytitle">glIsTexture</span></span></a>
        </p>
      </div>
      <div class='refsect1' id='examples'><h2>Examples</h2><div class='example'>Create a framebuffer object with a texture-based color attachment and a texture-based depth attachment. Using texture-based attachments allows sampling of those textures in shaders.<pre class='programlisting'><span class='codecomment'>// fbo_width and fbo_height are the desired width and height of the FBO.</span>
<span class='codecomment'>// For Opengl &lt;= 4.4 or <span class='ckeyword'>if</span> the <span class='constant'>GL_ARB_</span>texture_non_power_of_two extension</span>
<span class='codecomment'>// is present, fbo_width and fbo_height can be values other than 2^n <span class='ckeyword'>for</span></span>
<span class='codecomment'>// some integer n.</span>

<span class='codecomment'>// Build the texture that will serve as the color attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> texture_map;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;texture_map);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, texture_map);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_BORDER</span>);

<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_RGBA</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_RGBA</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);

<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the texture that will serve as the depth attachment <span class='ckeyword'>for</span> the framebuffer.</span>
<span class='ckeyword'>GLuint</span> depth_texture;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;depth_texture);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, depth_texture);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_NEAREST</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, fbo_width, fbo_height, 0, <span class='constant'>GL_DEPTH_COMPONENT</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, <span class='ckeyword'>NULL</span>);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);

<span class='codecomment'>// Build the framebuffer.</span>
<span class='ckeyword'>GLuint</span> framebuffer;
<a href='../gl4/glGenFramebuffers'>glGenFramebuffers</a>(1, &amp;framebuffer);
<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, (<span class='ckeyword'>GLuint</span>)framebuffer);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_COLOR_ATTACHMENT0</span>, <span class='constant'>GL_TEXTURE_2D</span>, texture_map, 0);
<a href='../gl4/glFramebufferTexture'>glFramebufferTexture2D</a>(<span class='constant'>GL_FRAMEBUFFER</span>, <span class='constant'>GL_DEPTH_ATTACHMENT</span>, <span class='constant'>GL_TEXTURE_2D</span>, depth_texture, 0);

<span class='ckeyword'>GLenum</span> status = <a href='../gl4/glCheckFramebufferStatus'>glCheckFramebufferStatus</a>(<span class='constant'>GL_FRAMEBUFFER</span>);
<span class='ckeyword'>if</span> (status != <span class='constant'>GL_FRAMEBUFFER_COMPLETE</span>)
    <span class='codecomment'>// Error</span>

<a href='../gl4/glBindFramebuffer'>glBindFramebuffer</a>(<span class='constant'>GL_FRAMEBUFFER</span>, 0);</pre></div><div class='example'>Create a texture object with linear mipmaps and edge clamping.<pre class='programlisting'><span class='ckeyword'>GLuint</span> texture_id;
<a href='../gl4/glGenTextures'>glGenTextures</a>(1, &amp;texture_id);
<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, texture_id);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MAG_FILTER</span>, <span class='constant'>GL_LINEAR</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_MIN_FILTER</span>, <span class='constant'>GL_LINEAR_MIPMAP_LINEAR</span>);

<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_S</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);
<a href='../gl4/glTexParameter'>glTexParameteri</a>(<span class='constant'>GL_TEXTURE_2D</span>, <span class='constant'>GL_TEXTURE_WRAP_T</span>, <span class='constant'>GL_CLAMP_TO_EDGE</span>);

<span class='codecomment'>// texture_data is the source data of your texture, in this <span class='ckeyword'>case</span></span>
<span class='codecomment'>// its size is <span class='ckeyword'>sizeof</span>(<span class='ckeyword'>unsigned</span> <span class='ckeyword'>char</span>) * texture_width * texture_height * 4</span>
<a href='../gl4/glTexImage2D'>glTexImage2D</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0, <span class='constant'>GL_RGBA</span>, texture_width, texture_height, 0, <span class='constant'>GL_RGBA</span>, <span class='constant'>GL_UNSIGNED_BYTE</span>, texture_data);
<a href='../gl4/glGenerateMipmap'>glGenerateMipmap</a>(<span class='constant'>GL_TEXTURE_2D</span>); <span class='codecomment'>// Unavailable in OpenGL 2.1, use gluBuild2DMipmaps() insteads.</span>

<a href='../gl4/glBindTexture'>glBindTexture</a>(<span class='constant'>GL_TEXTURE_2D</span>, 0);
</pre></div></div><div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://antongerdelan.net/opengl/cubemaps.html">Anton Gerdelan - Cube Maps: Sky Boxes and Environment Mapping</a><br /><a href="https://open.gl/framebuffers">open.gl - Framebuffers</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-14-render-to-texture/">opengl-tutorial.org - Tutorial 14 : Render To Texture</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-16-shadow-mapping/">opengl-tutorial.org - Tutorial 16 : Shadow mapping</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/">opengl-tutorial.org - Tutorial 5 : A Textured Cube</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glGenTextures</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glGenTextures.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glGenTextures glad_glGenTextures
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
GLAPI PFNGLISTEXTUREPROC glad_glIsTexture;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glIsTexture'>OpenGL 4</a><br /><a  href='../gl3/glIsTexture'>OpenGL 3</a><br /><a  href='../gl2/glIsTexture'>OpenGL 2</a><br /><a  href='../es3/glIsTexture'>OpenGL ES 3</a><br /><a  href='../es2/glIsTexture'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glIsTexture</h1>
    <div class="refentry" id="glIsTexture">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glIsTexture — determine if a name corresponds to a texture</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">GLboolean <strong class="fsfunc">glIsTexture</strong>(</code>
              </td>
              <td>GLuint <var class="pdparam">texture</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>texture</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a value that may be the name of a texture.
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glIsTexture</code> returns <code class="constant">GL_TRUE</code> if <em class="parameter"><code>texture</code></em> is currently the name of a texture.
            If <em class="parameter"><code>texture</code></em> is zero, or is a non-zero value that is not currently the
            name of a texture, or if an error occurs, <code class="function">glIsTexture</code> returns <code class="constant">GL_FALSE</code>.
        </p>
        <p>
            A name returned by <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>, but not yet associated with a texture
            by calling <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>, is not the name of a texture.
        </p>
      </div>
      
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glIsTexture</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glBindTexture"><span class="citerefentry"><span class="refentrytitle">glBindTexture</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage1D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage1D</span></span></a>,
            <a class="citerefentry" href="glCopyTexImage2D"><span class="citerefentry"><span class="refentrytitle">glCopyTexImage2D</span></span></a>,
            <a class="citerefentry" href="glDeleteTextures"><span class="citerefentry"><span class="refentrytitle">glDeleteTextures</span></span></a>,
            <a class="citerefentry" href="glGenTextures"><span class="citerefentry"><span class="refentrytitle">glGenTextures</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glGetTexParameter"><span class="citerefentry"><span class="refentrytitle">glGetTexParameter</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>,
            <a class="citerefentry" href="glTexParameter"><span class="citerefentry"><span class="refentrytitle">glTexParameter</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2010-2014 Khronos Group.
            This document is licensed under the SGI Free Software B License.
            For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glIsTexture.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glIsTexture glad_glIsTexture
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
GLAPI PFNGLARRAYELEMENTPROC glad_glArrayElement;
#define glArrayElement glad_glArrayElement
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLCOLORPOINTERPROC glad_glColorPointer;
#define glColorPointer glad_glColorPointer
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
GLAPI PFNGLDISABLECLIENTSTATEPROC glad_glDisableClientState;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glDisable'>OpenGL 4</a><br /><a  href='../gl3/glDisable'>OpenGL 3</a><br /><a  href='../gl2/glDisable'>OpenGL 2</a><br /><a  href='../es3/glDisable'>OpenGL ES 3</a><br /><a  href='../es2/glDisable'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glDisable</h1>
<script>window.location.replace("glEnable");</script>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glDisable.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glDisableClientState glad_glDisableClientState
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void *pointer);
GLAPI PFNGLEDGEFLAGPOINTERPROC glad_glEdgeFlagPointer;
#define glEdgeFlagPointer glad_glEdgeFlagPointer
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
GLAPI PFNGLENABLECLIENTSTATEPROC glad_glEnableClientState;
/**
<body><div id="khronos">
      <div id="command_versions"><a class='current' href='../gl4/glEnable'>OpenGL 4</a><br /><a  href='../gl3/glEnable'>OpenGL 3</a><br /><a  href='../gl2/glEnable'>OpenGL 2</a><br /><a  href='../es3/glEnable'>OpenGL ES 3</a><br /><a  href='../es2/glEnable'>OpenGL ES 2</a><br /></div>
      <h1 id="command_title">glEnable</h1>
    <div class="refentry" id="glEnable">
      <div class="titlepage"></div>
      <div class="refnamediv">
        <h2>Name</h2>
        <p>glEnable — enable or disable server-side GL capabilities</p>
      </div>
      <div class="refsynopsisdiv">
        <h2>C Specification</h2>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glEnable</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">cap</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDisable</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">cap</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glEnablei</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">cap</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
        <div class="funcsynopsis">
          <table style="border: 0; cellspacing: 0; cellpadding: 0;" class="funcprototype-table">
            <tr>
              <td>
                <code class="funcdef">void <strong class="fsfunc">glDisablei</strong>(</code>
              </td>
              <td>GLenum <var class="pdparam">cap</var>, </td>
            </tr>
            <tr>
              <td> </td>
              <td>GLuint <var class="pdparam">index</var><code>)</code>;</td>
            </tr>
          </table>
          <div class="funcprototype-spacer"> </div>
        </div>
      </div>
      <div class="refsect1" id="parameters">
        <h2>Parameters</h2>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>cap</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies a symbolic constant indicating a GL capability.
                </p>
            </dd>
            <dt>
              <span class="term">
                <em class="parameter">
                  <code>index</code>
                </em>
              </span>
            </dt>
            <dd>
              <p>
                    Specifies the index of the switch to disable (for
                    <code class="function">glEnablei</code> and
                    <code class="function">glDisablei</code> only).
                </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="description">
        <h2>Description</h2>
        <p>
            <code class="function">glEnable</code> and <code class="function">glDisable</code>
            enable and disable various capabilities. Use
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
            or
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>
            to determine the current setting of any capability. The initial
            value for each capability with the exception of
            <code class="constant">GL_DITHER</code> and
            <code class="constant">GL_MULTISAMPLE</code> is
            <code class="constant">GL_FALSE</code>. The initial value for
            <code class="constant">GL_DITHER</code> and
            <code class="constant">GL_MULTISAMPLE</code> is
            <code class="constant">GL_TRUE</code>.
        </p>
        <p>
            Both <code class="function">glEnable</code> and <code class="function">glDisable</code> take a single argument, <em class="parameter"><code>cap</code></em>,
            which can assume one of the following values:
        </p>
        <p>
            Some of the GL's capabilities are indexed. <code class="function">glEnablei</code> and <code class="function">glDisablei</code> enable and disable
            indexed capabilities.
        </p>
        <div class="variablelist">
          <dl class="variablelist">
            <dt>
              <span class="term">
                <code class="constant">GL_BLEND</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        blend the computed fragment color values with the values in the color
                        buffers. See <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CLIP_DISTANCE</code>
                <span class="emphasis">
                  <em>i</em>
                </span>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, clip geometry against user-defined half space <span class="emphasis"><em>i</em></span>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_COLOR_LOGIC_OP</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        apply the currently selected logical operation to the computed fragment
                        color and color buffer values. See <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_CULL_FACE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        cull polygons based on their winding in window coordinates.
                        See <a class="citerefentry" href="glCullFace"><span class="citerefentry"><span class="refentrytitle">glCullFace</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_OUTPUT</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, debug messages are produced by a debug context. When disabled,
                        the debug message log is silenced. Note that in a non-debug context, very
                        few, if any messages might be produced, even when <code class="constant">GL_DEBUG_OUTPUT</code>
                        is enabled.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEBUG_OUTPUT_SYNCHRONOUS</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, debug messages are produced synchronously by a debug context. If disabled,
                        debug messages may be produced asynchronously. In particular, they may be delayed relative
                        to the execution of GL commands, and the debug callback function may be called from
                        a thread other than that in which the commands are executed.
                        See <a class="citerefentry" href="glDebugMessageCallback"><span class="citerefentry"><span class="refentrytitle">glDebugMessageCallback</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_CLAMP</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        the

                        <math overflow="scroll">
                            <mo>-</mo><msub><mi>w</mi><mi>c</mi></msub><mo>≤</mo><msub><mi>z</mi><mi>c</mi></msub><mo>≤</mo><msub><mi>w</mi><mi>c</mi></msub>
                        </math>
                        plane equation is ignored by view volume clipping (effectively, there is no near or
                        far plane clipping).
                        See <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_DEPTH_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        do depth comparisons and update the depth buffer. Note that even if
                        the depth buffer exists and the depth mask is non-zero, the
                        depth buffer is not updated if the depth test is disabled. See
                        <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a> and
                        <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term"><code class="constant">GL_DITHER</code>    </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        dither color components or indices before they are written to the
                        color buffer.
                    </p>
            </dd>
            <dt>
              <span class="term"><code class="constant">GL_FRAMEBUFFER_SRGB</code>    </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled
                        and the value of <code class="constant">GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING</code> for the
                        framebuffer attachment corresponding to the destination buffer is <code class="constant">GL_SRGB</code>,
                        the R, G, and B destination color values (after conversion from fixed-point to floating-point)
                        are considered to be encoded for the sRGB color space and hence are linearized prior to
                        their use in blending.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_LINE_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        draw lines with correct filtering.
                        Otherwise,
                        draw aliased lines.
                        See <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_MULTISAMPLE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        use multiple fragment samples in computing the final color of a pixel.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_FILL</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, and if the polygon is rendered in
                        <code class="constant">GL_FILL</code> mode, an offset is added to depth values of a polygon's
                        fragments before the depth comparison is performed.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_LINE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, and if the polygon is rendered in
                        <code class="constant">GL_LINE</code> mode, an offset is added to depth values of a polygon's
                        fragments before the depth comparison is performed.
                        See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_OFFSET_POINT</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, an offset is added to depth values of a polygon's fragments
                        before the depth comparison is performed, if the polygon is rendered in
                        <code class="constant">GL_POINT</code> mode. See <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_POLYGON_SMOOTH</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, draw polygons with proper filtering.
                        Otherwise, draw aliased polygons. For correct antialiased polygons,
                        an alpha buffer is needed and the polygons must be sorted front to
                        back.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PRIMITIVE_RESTART</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        Enables primitive restarting.  If enabled, any one of the draw commands
                        which transfers a set of generic attribute array elements to the GL will restart
                        the primitive when the index of the vertex is equal to the primitive restart index.
                        See <a class="citerefentry" href="glPrimitiveRestartIndex"><span class="citerefentry"><span class="refentrytitle">glPrimitiveRestartIndex</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PRIMITIVE_RESTART_FIXED_INDEX</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        Enables primitive restarting with a fixed index. If enabled, any one of the
                        draw commands which transfers a set of generic attribute array elements to the GL will
                        restart the primitive when the index of the vertex is equal to the fixed primitive
                        index for the specified index type. The fixed index is equal to
                        <math overflow="scroll"><msup><mn>2</mn><mi>n</mi></msup><mo>−</mo><mn>1</mn></math>
                        where <span class="emphasis"><em>n</em></span> is equal to 8 for <code class="constant">GL_UNSIGNED_BYTE</code>,
                        16 for <code class="constant">GL_UNSIGNED_SHORT</code> and 32 for <code class="constant">GL_UNSIGNED_INT</code>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_RASTERIZER_DISCARD</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        primitives are discarded after the optional transform feedback stage,
                        but before rasterization. Furthermore, when enabled, <a class="citerefentry" href="glClear"><span class="citerefentry"><span class="refentrytitle">glClear</span></span></a>,
                        <a class="citerefentry" href="glClearBufferData"><span class="citerefentry"><span class="refentrytitle">glClearBufferData</span></span></a>,
                        <a class="citerefentry" href="glClearBufferSubData"><span class="citerefentry"><span class="refentrytitle">glClearBufferSubData</span></span></a>,
                        <a class="citerefentry" href="glClearTexImage"><span class="citerefentry"><span class="refentrytitle">glClearTexImage</span></span></a>, and
                        <a class="citerefentry" href="glClearTexSubImage"><span class="citerefentry"><span class="refentrytitle">glClearTexSubImage</span></span></a> are ignored.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_ALPHA_TO_COVERAGE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        compute a temporary coverage value where each bit is determined by the
                        alpha value at the corresponding sample location.  The temporary coverage
                        value is then ANDed with the fragment coverage value.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_ALPHA_TO_ONE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        each sample alpha value is replaced by the maximum representable alpha value.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_COVERAGE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        the fragment's coverage is ANDed with the temporary coverage value.  If
                        <code class="constant">GL_SAMPLE_COVERAGE_INVERT</code> is set to <code class="constant">GL_TRUE</code>, invert the coverage
                        value.
                        See <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_SHADING</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, the active fragment shader is run once for each covered sample, or at
                        fraction of this rate as determined by the current value of <code class="constant">GL_MIN_SAMPLE_SHADING_VALUE</code>.
                        See <a class="citerefentry" href="glMinSampleShading"><span class="citerefentry"><span class="refentrytitle">glMinSampleShading</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SAMPLE_MASK</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, the sample coverage mask generated for a fragment during rasterization
                        will be ANDed with the value of <code class="constant">GL_SAMPLE_MASK_VALUE</code> before
                        shading occurs.
                        See <a class="citerefentry" href="glSampleMaski"><span class="citerefentry"><span class="refentrytitle">glSampleMaski</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_SCISSOR_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        discard fragments that are outside the scissor rectangle.
                        See <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_STENCIL_TEST</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled,
                        do stencil testing and update the stencil buffer.
                        See <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a> and <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_TEXTURE_CUBE_MAP_SEAMLESS</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled, cubemap textures are sampled such that when linearly sampling from the border
                        between two adjacent faces, texels from both faces are used to generate the final sample
                        value. When disabled, texels from only a single face are used to construct the final
                        sample value.
                    </p>
            </dd>
            <dt>
              <span class="term">
                <code class="constant">GL_PROGRAM_POINT_SIZE</code>
              </span>
            </dt>
            <dd>
              <p>
                </p>
              <p>
                        If enabled
                        and a vertex or geometry shader is active, then the derived point size is taken from the (potentially clipped) shader builtin
                        <code class="constant">gl_PointSize</code> and clamped to the implementation-dependent point size range.
                    </p>
            </dd>
          </dl>
        </div>
      </div>
      <div class="refsect1" id="errors">
        <h2>Errors</h2>
        <p>
            <code class="constant">GL_INVALID_ENUM</code> is generated if <em class="parameter"><code>cap</code></em> is not one of the values
            listed previously.
        </p>
        <p>
            <code class="constant">GL_INVALID_VALUE</code> is generated by <code class="function">glEnablei</code> and <code class="function">glDisablei</code>
            if <em class="parameter"><code>index</code></em> is greater than or equal to the number of indexed capabilities for <em class="parameter"><code>cap</code></em>.
        </p>
      </div>
      <div class="refsect1" id="notes">
        <h2>Notes</h2>
        <p>
            <code class="constant">GL_PRIMITIVE_RESTART</code> is available only if the GL version is 3.1 or greater.
        </p>
        <p>
            <code class="constant">GL_TEXTURE_CUBE_MAP_SEAMLESS</code> is available only if the GL version is 3.2 or greater.
        </p>
        <p>
            <code class="constant">GL_PRIMITIVE_RESTART_FIXED_INDEX</code> is available only if the GL version is 4.3 or greater.
        </p>
        <p>
            <code class="constant">GL_DEBUG_OUTPUT</code> and <code class="constant">GL_DEBUG_OUTPUT_SYNCHRONOUS</code> are available only if the GL version is 4.3 or greater.
        </p>
        <p>
            Any token accepted by <code class="function">glEnable</code> or <code class="function">glDisable</code> is also accepted by
            <code class="function">glEnablei</code> and <code class="function">glDisablei</code>, but if the capability is not indexed,
            the maximum value that <em class="parameter"><code>index</code></em> may take is zero.
        </p>
        <p>
            In general, passing an indexed capability to <code class="function">glEnable</code> or <code class="function">glDisable</code>
            will enable or disable that capability for all indices, resepectively.
        </p>
      </div>
      <div class="refsect1" id="associatedgets">
        <h2>Associated Gets</h2>
        <p>
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>
        </p>
        <p>
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>
        </p>
      </div>
      <div class='refsect1' id='tutorials'><h2>Tutorials</h2><p><a href="https://antongerdelan.net/opengl/hellotriangle.html">Anton Gerdelan - "Hello Triangle" - OpenGL 4 Up and Running</a><br /><a href="https://antongerdelan.net/opengl/vertexbuffers.html">Anton Gerdelan - Vertex Buffer Objects</a><br /><a href="https://open.gl/depthstencils">open.gl - Depth and Stencil Buffers</a><br /><a href="https://open.gl/feedback">open.gl - Transform Feedback</a><br /><a href="https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-10-transparency/">opengl-tutorial.org - Tutorial 10 : Transparency</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/">opengl-tutorial.org - Tutorial 4 : A Colored Cube</a><br /><a href="https://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/">opengl-tutorial.org - Tutorial 5 : A Textured Cube</a><br /></p></div>
      <div class="refsect1" id="versions">
        <h2>Version Support</h2>
        <div class="informaltable">
          <table style="border-collapse: collapse; border-top: 2px solid ; border-bottom: 2px solid ; border-left: 2px solid ; border-right: 2px solid ; ">
            <colgroup>
              <col style="text-align: left; "/>
              <col style="text-align: center; " class="firstvers"/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; "/>
              <col style="text-align: center; " class="lastvers"/>
            </colgroup>
            <thead>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; ">

            </th>
                <th style="text-align: center; border-bottom: 2px solid ; " colspan="12">
                <span class="bold"><strong>OpenGL Version</strong></span>
            </th>
              </tr>
              <tr>
                <th style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>Function / Feature Name</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>2.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>3.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.0</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.1</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.2</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.3</strong></span>
            </th>
                <th style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.4</strong></span>
            </th>
                <th style="text-align: center; border-bottom: 2px solid ; ">
                <span class="bold"><strong>4.5</strong></span>
            </th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glDisable</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glDisablei</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; border-bottom: 2px solid ; ">
                  <code class="function">glEnable</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; border-bottom: 2px solid ; ">✔</td>
                <td style="text-align: center; border-bottom: 2px solid ; ">✔</td>
              </tr>
              <tr>
                <td style="text-align: left; border-right: 2px solid ; ">
                  <code class="function">glEnablei</code>
                </td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">-</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; border-right: 2px solid ; ">✔</td>
                <td style="text-align: center; ">✔</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
      <div class="refsect1" id="seealso">
        <h2>See Also</h2>
        <p>
            <a class="citerefentry" href="glActiveTexture"><span class="citerefentry"><span class="refentrytitle">glActiveTexture</span></span></a>,
            <a class="citerefentry" href="glBlendFunc"><span class="citerefentry"><span class="refentrytitle">glBlendFunc</span></span></a>,
            <a class="citerefentry" href="glCullFace"><span class="citerefentry"><span class="refentrytitle">glCullFace</span></span></a>,
            <a class="citerefentry" href="glDepthFunc"><span class="citerefentry"><span class="refentrytitle">glDepthFunc</span></span></a>,
            <a class="citerefentry" href="glDepthRange"><span class="citerefentry"><span class="refentrytitle">glDepthRange</span></span></a>,
            <a class="citerefentry" href="glGet"><span class="citerefentry"><span class="refentrytitle">glGet</span></span></a>,
            <a class="citerefentry" href="glIsEnabled"><span class="citerefentry"><span class="refentrytitle">glIsEnabled</span></span></a>,
            <a class="citerefentry" href="glLineWidth"><span class="citerefentry"><span class="refentrytitle">glLineWidth</span></span></a>,
            <a class="citerefentry" href="glLogicOp"><span class="citerefentry"><span class="refentrytitle">glLogicOp</span></span></a>,
            <a class="citerefentry" href="glPointSize"><span class="citerefentry"><span class="refentrytitle">glPointSize</span></span></a>,
            <a class="citerefentry" href="glPolygonMode"><span class="citerefentry"><span class="refentrytitle">glPolygonMode</span></span></a>,
            <a class="citerefentry" href="glPolygonOffset"><span class="citerefentry"><span class="refentrytitle">glPolygonOffset</span></span></a>,
            <a class="citerefentry" href="glSampleCoverage"><span class="citerefentry"><span class="refentrytitle">glSampleCoverage</span></span></a>,
            <a class="citerefentry" href="glScissor"><span class="citerefentry"><span class="refentrytitle">glScissor</span></span></a>,
            <a class="citerefentry" href="glStencilFunc"><span class="citerefentry"><span class="refentrytitle">glStencilFunc</span></span></a>,
            <a class="citerefentry" href="glStencilOp"><span class="citerefentry"><span class="refentrytitle">glStencilOp</span></span></a>,
            <a class="citerefentry" href="glTexImage1D"><span class="citerefentry"><span class="refentrytitle">glTexImage1D</span></span></a>,
            <a class="citerefentry" href="glTexImage2D"><span class="citerefentry"><span class="refentrytitle">glTexImage2D</span></span></a>,
            <a class="citerefentry" href="glTexImage3D"><span class="citerefentry"><span class="refentrytitle">glTexImage3D</span></span></a>
        </p>
      </div>
      <div class="refsect1" id="Copyright">
        <h2>Copyright</h2>
        <p>
            Copyright © 1991-2006 Silicon Graphics, Inc.
            Copyright © 2011-2014 Khronos Group.
            This document is licensed under the SGI
            Free Software B License. For details, see
            <a class="link" href="https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/" target="_top">https://web.archive.org/web/20171022161616/http://oss.sgi.com/projects/FreeB/</a>.
        </p>
      </div>
    </div>

</div>

<div id="improvepage">Think you can improve this page? <a href='https://github.com/BSVino/docs.gl/blob/master/gl4/glEnable.xhtml'>Edit this page</a> on <a href='https://github.com/BSVino/docs.gl/'>GitHub</a>.</div>
</div>

<div id="footer">
<div id="credits"><a href="https://docs.gl/">docs.gl</a> was written by <a href="https://twitter.com/VinoBS">Jorge Rodr&iacute;guez</a>. Each entry is under individual copyright displayed at the bottom of that entry. All other content is in the public domain.<br />
docs.gl is completely unaffiliated with OpenGL and Khronos.<br />
These pages were last compiled on 20 July 2020 at 20:16:04 GMT.</div>
</div>

<script async src="../docs.gl.search.js"></script>
</body>
</html>
*/

#define glEnableClientState glad_glEnableClientState
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLINDEXPOINTERPROC glad_glIndexPointer;
#define glIndexPointer glad_glIndexPointer
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void *pointer);
GLAPI PFNGLINTERLEAVEDARRAYSPROC glad_glInterleavedArrays;
#define glInterleavedArrays glad_glInterleavedArrays
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLNORMALPOINTERPROC glad_glNormalPointer;
#define glNormalPointer glad_glNormalPointer
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLTEXCOORDPOINTERPROC glad_glTexCoordPointer;
#define glTexCoordPointer glad_glTexCoordPointer
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI PFNGLVERTEXPOINTERPROC glad_glVertexPointer;
#define glVertexPointer glad_glVertexPointer
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
GLAPI PFNGLARETEXTURESRESIDENTPROC glad_glAreTexturesResident;
#define glAreTexturesResident glad_glAreTexturesResident
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
GLAPI PFNGLPRIORITIZETEXTURESPROC glad_glPrioritizeTextures;
#define glPrioritizeTextures glad_glPrioritizeTextures
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
GLAPI PFNGLINDEXUBPROC glad_glIndexub;
#define glIndexub glad_glIndexub
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte *c);
GLAPI PFNGLINDEXUBVPROC glad_glIndexubv;
#define glIndexubv glad_glIndexubv
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)(void);
GLAPI PFNGLPOPCLIENTATTRIBPROC glad_glPopClientAttrib;
#define glPopClientAttrib glad_glPopClientAttrib
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
GLAPI PFNGLPUSHCLIENTATTRIBPROC glad_glPushClientAttrib;
#define glPushClientAttrib glad_glPushClientAttrib
#endif
#endif